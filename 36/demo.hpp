//
// Created by mars on 2021/8/25.
//

/*
 * Item36:绝不重新定义继承而来的non-virtual函数
 * 如果要维持“不变性凌驾特异性”的性质，即子类对象也是一个父类对象，
 * 子类的non-virtual应完全由父类继承而来并避免重定义。
 * 应该将需要不同实现的方法声明为virtual方法。
 */

#ifndef INC_36__DEMO_HPP_
#define INC_36__DEMO_HPP_

#include <iostream>

class B {
 public:
  void mf() {
	std::cout << "B::mf" << std::endl;
  }
};

class C : public B{
//继承自父类的mf方法
};

class D : public B{
 public:
  //重定义父类的方法，父类的方法被遮掩,可以通过B::mf()调用
  void mf() {
	std::cout << "D::mf" << std::endl;
	//B::mf();
  }
};

#if 0

/*
 * non-virtual函数是静态绑定的(statically bound)
 * 由于pB (B*) / rB (B&)被声明为 pointer-to-B/ reference-to-B,
 * 通过pB/rB调用的non-virtaul永远是B定义的版本，即使其指向/引用B的派生类对象。
 * 与之相反的，virtual函数是动态绑定的(dynamically bound)，
 * 不论是通过pB/rB还是通过pD/rD调用，其指向/引用的都是一个类型为D的对象。
 */

  B b;C c;D d;
  b.mf();c.mf();d.mf();
-------------------------------------------
  D db;
  B* pB = &db;
  D* pD = &db;
  B& rB = db;
  pB->mf();
  pD->mf();
  B& rB = db;
  rB.mf();
  D& rD = db;
  rD.mf();


===========================================
B::mf
B::mf
D::mf
-------------------------------------------
B::mf
D::mf
B::mf
D::mf
===========================================

#endif

#endif //INC_36__DEMO_HPP_
