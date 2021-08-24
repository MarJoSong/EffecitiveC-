//
// Created by mars on 2021/8/24.
//

#ifndef INC_35_CMAKE_BUILD_DEBUG_WAY1_HPP_
#define INC_35_CMAKE_BUILD_DEBUG_WAY1_HPP_

/*
 * 1.�� NVI(Non-Virtual Interface) �ַ�ʵ�� Template Method ģʽ��
 * ������ healthValue Ϊ public ��Ա����������Ϊ no-virtual��������һ�� private virtual��Ա������
 * ���԰���� public ������Ϊ private virtual �� wrapper(�⸲��)
 * ��ͻ�ͨ�� public non-virtual ��ӵ��� private virtual �� Template Method ���ģʽ��
 */
class GameCharacter1 {
 public:
  int healthValue() const { //derived class �����¶���˷���
	//TODO	׼����������������־����֤��
	int retVal = doHealthValue();
	//TODO	�ƺ���
	return retVal;
  }

 private:
  virtual int doHealthValue() const {    //derived class �����¶���˷���
	std::cout << "base doHealthValue called" << std::endl;
	return 100;
  }
};

class Monster : public GameCharacter1 {
 private:
  int doHealthValue() const override {    //derived class �����¶���˷���
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
