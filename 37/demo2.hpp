//
// Created by mars on 2021/8/25.
//

#ifndef INC_37__DEMO1_HPP_
#define INC_37__DEMO1_HPP_

#include <iostream>

/*
 * ����demo1���������Ի��ԣ�������non-virtual��д�������
 * ��ΪItem36���麯����Ӧ�ñ��ض��壬�������ǿ�����Ϊ���õ����Ǹ����getCount��
 * ��ȱʡ����Ҳ���õĸ��ຯ����ȱʡ����(��ȻgetCount����õ��ǻ��������Լ���gCount)��
 * ��������������36������demo1���Ի��ԡ�
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
  ptu->gCount(); 	//����TenUnit::gCount ==> 10

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
