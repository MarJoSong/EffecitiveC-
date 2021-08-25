//
// Created by mars on 2021/8/25.
//

/*
 * Item36:�������¶���̳ж�����non-virtual����
 * ���Ҫά�֡���������������ԡ������ʣ����������Ҳ��һ���������
 * �����non-virtualӦ��ȫ�ɸ���̳ж����������ض��塣
 * Ӧ�ý���Ҫ��ͬʵ�ֵķ�������Ϊvirtual������
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
//�̳��Ը����mf����
};

class D : public B{
 public:
  //�ض��常��ķ���������ķ���������,����ͨ��B::mf()����
  void mf() {
	std::cout << "D::mf" << std::endl;
	//B::mf();
  }
};

#if 0

/*
 * non-virtual�����Ǿ�̬�󶨵�(statically bound)
 * ����pB (B*) / rB (B&)������Ϊ pointer-to-B/ reference-to-B,
 * ͨ��pB/rB���õ�non-virtaul��Զ��B����İ汾����ʹ��ָ��/����B�����������
 * ��֮�෴�ģ�virtual�����Ƕ�̬�󶨵�(dynamically bound)��
 * ������ͨ��pB/rB����ͨ��pD/rD���ã���ָ��/���õĶ���һ������ΪD�Ķ���
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
