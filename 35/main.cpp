#include <iostream>
#include "way1.hpp"
#include "way2.hpp"
#include "way3.hpp"
#include "way4.hpp"

class GameCharacter0 {
 public:
  virtual int healthValue() const {
	return 100;
  } //���������Ѫ����δ����Ϊ pure virtual ,��ζ�ű���Ҫ��һ��ȱʡʵ��
};

//���� GameCharacter ����������� overriding(��д/����) ����ķ������Բ�ͬ��ʽ����Ѫ��
//������virtual��������ķ�����ʵ�ִ˹���


int main() {
#if 0
  GameCharacter1 base;
  base.healthValue();

  Monster monster;
  monster.healthValue();
#endif

#if 0
  EvilBadGuy2 ebg1(HealthQuickly2);
  ebg1.healthValue();

  EvilBadGuy2 ebg2(HealthSlowly2);
  ebg2.healthValue();
#endif

#if 0
  EvilBadGuy3 ebg1(HealthQuickly3);
  ebg1.healthValue();

  EvilBadGuy3 ebg2((HealthCalculator()));
  ebg2.healthValue();

  HealthClass health_class;
  EvilBadGuy3 ebg3(std::bind(&HealthClass::health_local, health_class, std::placeholders::_1));
  ebg3.healthValue();

  EvilBadGuy3 ebg4(std::bind(&HealthClass::health_static, std::placeholders::_1));
  ebg4.healthValue();

  EvilBadGuy3 ebg5([](const GameCharacter3 &gc) -> int {
    std::cout << "lambda expression called" << std::endl;
    return 100;
  });
  ebg5.healthValue();
#endif

  GameCharacter4 gc4(new HealthClass4());
  gc4.healthValue();

  return 0;
}
