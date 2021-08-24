//
// Created by mars on 2021/8/24.
//

#ifndef INC_35__WAY2_HPP_
#define INC_35__WAY2_HPP_

/*
 * 2.�� Function Pointers ʵ�� Strategy ģʽ��
 * ���ں���ָ�����ͨ�����캯���ȷ������ݸ����󣬸�����
 * Ҳ�����������ڱ����ʹ��ͬһ���͵Ĳ�ͬʵ�����ӵ�в�ͬ��Ѫ�����㺯����
 * ȱ������Ϊ non-member non-friend �����޷����� EvilBadGuy �� non-public ��Ա��
 * ���԰Ѽ��㺯������Ϊ��Ԫ��������˽��� class �ķ�װ�ԡ�
 */

class GameCharacter2;    //forward declaration (ǰ������)

int defaultHealthCalc2(const GameCharacter2 &gc);

class GameCharacter2 {
 public:
  typedef int (*HealthCalcFunc)(const GameCharacter2 &gc);
  explicit GameCharacter2(HealthCalcFunc hcf = defaultHealthCalc2)
	  : healthFunc(hcf) {}

  int healthValue() const {
	std::cout << "base healthValue called" << std::endl;
	return healthFunc(*this);
  };

 private:
  HealthCalcFunc healthFunc;
};

class EvilBadGuy2 : public GameCharacter2 {
 public:
  typedef int (*HealthCalcFunc)(const GameCharacter2 &gc);
  explicit EvilBadGuy2(HealthCalcFunc hcf = defaultHealthCalc2)
	  : GameCharacter2(hcf) {};

  /*
   * ����̳��Ը���Ĺ��г�Ա����healthValue���������˸����˽�г�ԱhealthFunc
   * �����ڲ���this������const GameCharacter2 * const;
   */
};

int HealthQuickly2(const GameCharacter2 &gc) {
  std::cout << "HealthQuickly2 called" << std::endl;
  return 100;
}

int HealthSlowly2(const GameCharacter2 &gc) {
  std::cout << "HealthSlowly2 called" << std::endl;
  return 100;
}

#if 0

  EvilBadGuy2 ebg1(HealthQuickly2);
  ebg1.healthValue();

  EvilBadGuy2 ebg2(HealthSlowly2);
  ebg2.healthValue();

============================================
Output:
base healthValue called
HealthQuickly2 called
base healthValue called
HealthSlowly2 called
============================================

  EvilBadGuy2 ebg3(defaultHealthCalc2);
  ebg2.healthValue();
============================================
defaultHealthCalc2δ���壬���뱨��
============================================


#endif

#endif //INC_35__WAY2_HPP_
