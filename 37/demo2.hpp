//
// Created by mars on 2021/8/25.
//

#ifndef INC_37__DEMO1_HPP_
#define INC_37__DEMO1_HPP_

#include <iostream>

/*
 * 鉴于demo1所产生的迷惑性，我们以non-virtual改写这个函数
 * 因为Item36非虚函数不应该被重定义，所以我们可以认为调用的总是父类的getCount，
 * 其缺省参数也引用的父类函数的缺省参数(虽然getCount里调用的是还是子类自己的gCount)，
 * 但我们利用条款36避免了demo1的迷惑性。
 */

class Unit {
 public:
  enum UnitCount {One = 1, Ten = 10, Hun = 100, Thu = 1000};
  void getCount(UnitCount count = One) {
	gCount(count);
  };
 private:
  virtual void gCount(UnitCount count = One) const = 0;
};

class TenUnit : public Unit{
 private:
  virtual void gCount(UnitCount count) const {
    std::cout << "TenUnit:" << count << std::endl;
  };
};

class HunUnit : public Unit{
 private:
  virtual void gCount(UnitCount count) const {
	std::cout << "HunUnit:" << count << std::endl;
  };
};

#if 0
  Unit *pu;
  auto *ptu = new TenUnit; //TenUnit* ptu;
  auto *phu = new HunUnit; //HunUnit* phu;
  ptu->gCount(); 	//调用TenUnit::gCount ==> 10

  pu = ptu;
  pu->gCount();
  pu = phu;
  pu->gCount();

=========================================
TenUnit:1
TenUnit:1
HunUnit:1
=========================================
#endif


#endif //INC_37__DEMO1_HPP_
