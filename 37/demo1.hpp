//
// Created by mars on 2021/8/25.
//

#ifndef INC_37__DEMO1_HPP_
#define INC_37__DEMO1_HPP_

#include <iostream>

/*
 * Item37:�������¶���̳ж�����(�麯����)ȱʡ����ֵ
 * ��Ϊvirtual�����Ƕ�̬��(dynamically bound, Ҳ�к��ڰ�late binding)�ģ�
 * ��ȱʡ����ֵȷʵ��̬��(statically bound, Ҳ��ǰ�ڰ�early binding)�ġ�
 * (�ض���non-virtual���Ǵ���ģ����Ժ����������)
 *
 * ��������Ĳ�������
 * ==============> ���ú�ָ�����ͬ�������� <==============
 * C++��������ֹ��ŵķ�ʽ��������Ϊ��������Ч��
 * ���ȱʡ�����Ƕ�̬�󶨣�������ĳ�ֻ�����������Ϊ virtual���� �����ʵ��Ĳ���ȱʡֵ��
 * ��Ŀǰʩ�е�"�ڱ����ھ���"�Ļ��Ƹ��������ӡ�
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
  virtual void gCount(UnitCount count) const { // ���￴����Ĳ�������˵��
	std::cout << "HunUnit:" << count << std::endl;
  }
};

class ThuUnit : public Unit{
 public:
  //�ṩͬ����ȱʡ������������ͻ���Ҳ���޴��ģ���ɴ����ظ���ͬʱ�����˴��������ԣ������������ı��ˣ�������Ҳ��Ҫ�޸�
  virtual void gCount(UnitCount count = One) const { // ���￴����Ĳ�������˵��
	std::cout << "ThuUnit:" << count << std::endl;
  }
};

#if 0
  Unit *pu;
  auto *ptu = new TenUnit; //TenUnit* ptu;
  auto *phu = new HunUnit; //HunUnit* phu;
  //pu->gCount();   //����澯�����г���puû�з����ڴ棬����Unit�ǳ������޷�ʵ����
  ptu->gCount(); 	//����TenUnit::gCount ==> 10
  //phu->gCount();	//���뱨��HunUnit::gCount�����ṩ����ֵ

  pu = ptu;
  //�麯����̬�󶨣�puʵ��ָ����һ��TenUnit���󣬵���TenUnit::gCount
  //������Ӧ�����10����ʵ�����==>1����Ϊȱʡ����ȴ�Ǿ�̬�󶨵ģ��õ���pu����������Unit�У�ͬ��������ȱʡ����
  pu->gCount();
  pu = phu;
  //pu��Ȼָ����һ��HunUnit���󣬵�����gCount�������ϻᱨ����ʵ����ȴʹ����Unit::gCount�е�ȱʡ����
  pu->gCount();

#endif


#endif //INC_37__DEMO1_HPP_
