//
// Created by mars on 2021/8/26.
//

#ifndef INC_43__DEMO2_HPP_
#define INC_43__DEMO2_HPP_

// 令C++ "不进入templatized base classes观察" 的行为失效的第二个办法
// 使用using声明式将 "被掩盖的基类名称" 带入一个派生类作用域中
// 这里其实不是基类名称被遮掩，而是编译器不进入基类作用域查找

class CompanyA {
 public:
  void sendClearText(const std::string &msg);
  void sendEncrypted(const std::string &msg);
};

class CompanyB {
 public:
  void sendClearText(const std::string &msg);
  void sendEncrypted(const std::string &msg);
};

class MsgInfo {};

template<typename Company>
class MsgSender {
 public:
  void sendClear(const MsgInfo &info) {
	std::string msg;
	Company c;
	c.sendClearText(msg);
  }

  void sendSecret(const MsgInfo &info) {};
};

template<typename Company>
class LoggingMsgSender : public MsgSender<Company> {
 public:
  //告诉编译器，请它 “假设” sendClear位于基类内
  using MsgSender<Company>::sendClear;
  void sendClearMsg(const MsgInfo& info) {
	sendClear(info); //成立，sendClear被继承
  }
};

#endif //INC_43__DEMO2_HPP_
