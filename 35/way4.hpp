//
// Created by mars on 2021/8/24.
//

#ifndef INC_35__WAY4_HPP_
#define INC_35__WAY4_HPP_

/*
 * 4.�ŵ� Strategy ģʽ��
 * ��Ѫ�����㺯������һ������ļ̳���ϵ�е����Ա����
 */

class GameCharacter4;    //forward declaration (ǰ������)

class HealthClass4{
 public:
  virtual int calc(const GameCharacter4 &gc) const {
	std::cout << "class HealthClass4 called" << std::endl;
    return 100;
  }
};

HealthClass4 defaultHealthCalc4;

class GameCharacter4 {
 public:
  explicit GameCharacter4(HealthClass4* p_hcf = &defaultHealthCalc4)
	  : p_healthFunc(p_hcf) {}

  int healthValue() const {
	std::cout << "base healthValue called" << std::endl;
	return p_healthFunc->calc(*this);
  };

 private:
  HealthClass4 *p_healthFunc;
};

#if 0

  GameCharacter4 gc4(new HealthClass4());
  gc4.healthValue();

============================================
Output:
base healthValue called
class HealthClass4 called
============================================

#endif

#endif //INC_35__WAY4_HPP_
