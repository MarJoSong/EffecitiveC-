//
// Created by mars on 2021/8/24.
//

#ifndef INC_35__WAY2_HPP_
#define INC_35__WAY2_HPP_

/*
 * 2.由 Function Pointers 实现 Strategy 模式。
 * 由于函数指针可以通过构造函数等方法传递给对象，更加灵活，
 * 也可以在运行期变更，使得同一类型的不同实体可以拥有不同的血量计算函数，
 * 缺点是作为 non-member non-friend 函数无法访问 EvilBadGuy 的 non-public 成员，
 * 可以把计算函数声明为友元，但会因此降低 class 的封装性。
 */

class GameCharacter2;    //forward declaration (前置声明)

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
   * 这里继承自父类的公有成员函数healthValue函数调用了父类的私有成员healthFunc
   * 函数内部的this类型是const GameCharacter2 * const;
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
defaultHealthCalc2未定义，编译报错
============================================


#endif

#endif //INC_35__WAY2_HPP_
