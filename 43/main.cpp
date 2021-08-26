#include <iostream>

//条款43：学习处理模板化基类内的名称

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

	/*
	 * 调用基类函数，编译报错，原因如下
	 * LoggingMsgSender继承自MsgSender<Company>，而Company是一个template参数
	 * 即MsgSender<Company>是一个模板类，既然是模板，就可以对模板进行特化(半特化，全特化)
	 * 也许存在下面一个MsgSender全特化，其并不提供SendClear成员函数，
	 * (即使不存在这样的特化，但是编译器并不知道其不存在)
	 * 因此它往往拒绝在模板化基类(即本例的MsgSender<Company>)内寻找继承而来的名称(SendClear)
	 */
	sendClear(info);
  }
};

//===================================================================

class CompanyZ {
 public:
  void sendEncrypted(const std::string &msg);
};
//也许存在，也许不存在的全特化模板类
template<>
class MsgSender<CompanyZ> {
 public:
  void sendSecret(const MsgInfo &info) {};
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
