//
// Created by mars on 2021/8/26.
//

#ifndef INC_43__DEMO3_HPP_
#define INC_43__DEMO3_HPP_

// 令C++ "不进入templatized base classes观察" 的行为失效的第三个办法
// 明确指出被调用的函数位于基类内MsgSender<Company>::sendClear(info)
// 如果被调用的是virtual函数，会导致动态绑定属性失效


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
  void sendClearMsg(const MsgInfo& info) {
	MsgSender<Company>::sendClear(info); //成立，sendClear被继承
  }
};

#endif //INC_43__DEMO3_HPP_
