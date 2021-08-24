//
// Created by mars on 2021/8/24.
//

#ifndef INC_35__WAY3_HPP_
#define INC_35__WAY3_HPP_

/*
 * 3.�� std::function ʵ�� Strategy ģʽ��
 * std::function����ɳ���(����)�κοɵ�����(callable entity)��������ָ�룬�º�����lambda�������Ա����ָ��(������̬��Ա)��
 * ֻҪstd::function�������͵�������ݣ���仰����˼�ǣ�
 * ת�����std::function����Ĳ�����ת��Ϊ�ɵ���ʵ��Ĳ�����
 * ����ʵ��ķ���ֵ��ת��Ϊstd::function����ķ���ֵ��
 * ��Function Pointers�����е��ԡ�
 */
#include <functional>

class GameCharacter3;    //forward declaration (ǰ������)

int defaultHealthCalc3(const GameCharacter3 &gc);

class GameCharacter3 {
 public:
  typedef std::function<int (const GameCharacter3 &gc)> HealthCalcFunc3;
  explicit GameCharacter3(HealthCalcFunc3 hcf = defaultHealthCalc3)
	  : healthFunc(hcf) {}

  int healthValue() const {
	std::cout << "base healthValue called" << std::endl;
	return healthFunc(*this);
  };

 private:
  HealthCalcFunc3 healthFunc;
};

class EvilBadGuy3 : public GameCharacter3 {
 public:
  typedef std::function<int (const GameCharacter3 &gc)> HealthCalcFunc3;
  explicit EvilBadGuy3(HealthCalcFunc3 hcf = defaultHealthCalc3)
	  : GameCharacter3(hcf) {};

  /*
   * ����̳��Ը���Ĺ��г�Ա����healthValue���������˸����˽�г�ԱhealthFunc
   * �����ڲ���this������const GameCharacter2 * const;
   */
};

short HealthQuickly3(const GameCharacter3 &gc) {
  std::cout << "HealthQuickly3 called" << std::endl;
  return 100;
}

struct HealthCalculator {
  int operator()(const GameCharacter3 &gc) const {
	std::cout << "struct HealthCalculator() called" << std::endl;
	return 100;
  }
};

class HealthClass {
 public:
  //health_local��Ա����ʵ���ϰ���������������һ����thisָ�룬�ڶ�������const GameCharacter3 &gc
  float health_local(const GameCharacter3 &gc) {
	std::cout << "mem-function HealthClass::health called" << std::endl;
	return 100;
  }
  static float health_static(const GameCharacter3 &gc) {
	std::cout << "mem-function HealthClass::health called" << std::endl;
	return 100;
  }
};

#if 0
  //��ͨ����
  EvilBadGuy3 ebg1(HealthQuickly3);
  ebg1.healthValue();

  //�º�������
  EvilBadGuy3 ebg2((HealthCalculator()));
  ebg2.healthValue();

  //��ͨ��Ա
  HealthClass health_class;
  EvilBadGuy3 ebg3(std::bind(&HealthClass::health_local, health_class, std::placeholders::_1));
  /*
   * ����չ����healthFunc = std::bind(&HealthClass::health_local, health_class, std::placeholders::_1)
   * HealthClass::health_local��Ա����ʵ���ϰ���������������һ����thisָ�룬�ڶ�������const GameCharacter3 &gc
   *
   * ����һ��std::bind��䣬��������healthFunc�ĵ���ָ��&HealthClass::health_local��������������չ��
   * ��ʽ��HealthClass::health_local(&health_class, std::placeholders::_1)
   *
   * std::placeholders::_1��˼��healthFunc�ĵ�һ�ݲ����滻std::placeholders::_1������
   * �����HealthClass::health_local(&health_class, const GameCharacter3 &gc)
   */

  ebg3.healthValue();

  //��̬��Ա
  //
  EvilBadGuy3 ebg4(std::bind(&HealthClass::health_static, std::placeholders::_1));
  ebg4.healthValue();

  //lambda
  EvilBadGuy3 ebg5([](const GameCharacter3 &gc) -> int {
    std::cout << "lambda expression called" << std::endl;
    return 100;
  });
  ebg5.healthValue();

============================================
base healthValue called
HealthQuickly3 called
base healthValue called
struct HealthCalculator() called
base healthValue called
mem-function HealthClass::health called
base healthValue called
mem-function HealthClass::health called
base healthValue called
lambda expression called

�����ѽ������˳�����Ϊ 0

============================================

#endif

#endif //INC_35__WAY3_HPP_
