//
// Created by mars on 2021/8/24.
//

#ifndef INC_35__WAY3_HPP_
#define INC_35__WAY3_HPP_

/*
 * 3.由 std::function 实现 Strategy 模式。
 * std::function对象可持有(保存)任何可调用物(callable entity)，即函数指针，仿函数，lambda，或类成员函数指针(包括静态成员)，
 * 只要std::function的声明和调用物兼容，这句话的意思是：
 * 转换后的std::function对象的参数能转换为可调用实体的参数；
 * 调用实体的返回值能转换为std::function对象的返回值。
 * 比Function Pointers更具有弹性。
 */
#include <functional>

class GameCharacter3;    //forward declaration (前置声明)

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
   * 这里继承自父类的公有成员函数healthValue函数调用了父类的私有成员healthFunc
   * 函数内部的this类型是const GameCharacter2 * const;
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
  //health_local成员函数实际上包含两个参数，第一个是this指针，第二个才是const GameCharacter3 &gc
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
  //普通函数
  EvilBadGuy3 ebg1(HealthQuickly3);
  ebg1.healthValue();

  //仿函数对象
  EvilBadGuy3 ebg2((HealthCalculator()));
  ebg2.healthValue();

  //普通成员
  HealthClass health_class;
  EvilBadGuy3 ebg3(std::bind(&HealthClass::health_local, health_class, std::placeholders::_1));
  /*
   * 构造展开后即healthFunc = std::bind(&HealthClass::health_local, health_class, std::placeholders::_1)
   * HealthClass::health_local成员函数实际上包含两个参数，第一个是this指针，第二个才是const GameCharacter3 &gc
   *
   * 分析一下std::bind语句，功能是让healthFunc的调用指向&HealthClass::health_local，参数从左至右展开
   * 格式是HealthClass::health_local(&health_class, std::placeholders::_1)
   *
   * std::placeholders::_1意思是healthFunc的第一份参数替换std::placeholders::_1参数，
   * 最后变成HealthClass::health_local(&health_class, const GameCharacter3 &gc)
   */

  ebg3.healthValue();

  //静态成员
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

进程已结束，退出代码为 0

============================================

#endif

#endif //INC_35__WAY3_HPP_
