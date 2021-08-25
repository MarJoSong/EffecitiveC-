//
// Created by mars on 2021/8/25.
//

#ifndef INC_37__DEMO1_HPP_
#define INC_37__DEMO1_HPP_

#include <iostream>

/*
 * Item37:绝不重新定义继承而来的(虚函数的)缺省参数值
 * 因为virtual函数是动态绑定(dynamically bound, 也叫后期绑定late binding)的，
 * 而缺省参数值确实静态绑定(statically bound, 也叫前期绑定early binding)的。
 * (重定义non-virtual总是错误的，所以忽略这个讨论)
 *
 * 看最下面的测试用例
 * ==============> 引用和指针存在同样的问题 <==============
 * C++坚持以这种乖张的方式来运作是为了运行期效率
 * 如果缺省参数是动态绑定，必须有某种机制在运行期为 virtual函数 决定适当的参数缺省值，
 * 比目前施行的"在编译期决定"的机制更慢更复杂。
 */

class Unit {
 public:
  enum UnitCount {One = 1, Ten = 10, Hun = 100, Thu = 1000};
  virtual void gCount(UnitCount count = One) const = 0;
};

class TenUnit : public Unit{
 public:
  virtual void gCount(UnitCount count = Ten) const {
    std::cout << "TenUnit:" << count << std::endl;
  };
};

class HunUnit : public Unit{
 public:
  virtual void gCount(UnitCount count) const { // 这里看下面的测试用例说明
	std::cout << "HunUnit:" << count << std::endl;
  }
};

class ThuUnit : public Unit{
 public:
  //提供同样的缺省参数给派生类和基类也是愚蠢的，造成代码重复的同时带来了代码相依性，如果基类参数改变了，派生类也需要修改
  virtual void gCount(UnitCount count = One) const { // 这里看下面的测试用例说明
	std::cout << "ThuUnit:" << count << std::endl;
  }
};

#if 0
  Unit *pu;
  auto *ptu = new TenUnit; //TenUnit* ptu;
  auto *phu = new HunUnit; //HunUnit* phu;
  //pu->gCount();   //编译告警，运行出错，pu没有分配内存，而且Unit是抽象类无法实例化
  ptu->gCount(); 	//调用TenUnit::gCount ==> 10
  //phu->gCount();	//编译报错，HunUnit::gCount必须提供参数值

  pu = ptu;
  //虚函数动态绑定，pu实际指向了一个TenUnit对象，调用TenUnit::gCount
  //理论上应该输出10，但实际输出==>1，因为缺省参数却是静态绑定的，用的是pu的声明类型Unit中，同名方法的缺省参数
  pu->gCount();
  pu = phu;
  //pu虽然指向了一个HunUnit对象，调用其gCount，理论上会报错，但实际上却使用了Unit::gCount中的缺省参数
  pu->gCount();

#endif


#endif //INC_37__DEMO1_HPP_
