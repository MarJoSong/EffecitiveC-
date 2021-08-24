//
// Created by mars on 2021/8/24.
//

#ifndef INC_35_CMAKE_BUILD_DEBUG_WAY1_HPP_
#define INC_35_CMAKE_BUILD_DEBUG_WAY1_HPP_

/*
 * 1.由 NVI(Non-Virtual Interface) 手法实现 Template Method 模式。
 * 即保留 healthValue 为 public 成员，但让它成为 no-virtual，并调用一个 private virtual成员函数。
 * 可以把这个 public 函数称为 private virtual 的 wrapper(外覆器)
 * 令客户通过 public non-virtual 间接调用 private virtual 即 Template Method 设计模式。
 */
class GameCharacter1 {
 public:
  int healthValue() const { //derived class 不重新定义此方法
	//TODO	准备工作，加锁，日志，验证等
	int retVal = doHealthValue();
	//TODO	善后工作
	return retVal;
  }

 private:
  virtual int doHealthValue() const {    //derived class 可重新定义此方法
	std::cout << "base doHealthValue called" << std::endl;
	return 100;
  }
};

class Monster : public GameCharacter1 {
 private:
  int doHealthValue() const override {    //derived class 可重新定义此方法
	std::cout << "derived doHealthValue called" << std::endl;
	return 100;
  }
};

#if 0

  GameCharacter1 base;
  base.healthValue();

  Monster monster;
  monster.healthValue();

============================================
base doHealthValue called
derived doHealthValue called
============================================

#endif

#endif //INC_35_CMAKE_BUILD_DEBUG_WAY1_HPP_
