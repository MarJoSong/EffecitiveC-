//
// Created by mars on 2021/8/26.
//

#ifndef INC_43_CMAKE_BUILD_DEBUG_DEMO1_HPP_
#define INC_43_CMAKE_BUILD_DEBUG_DEMO1_HPP_

// ��C++ "������templatized base classes�۲�" ����ΪʧЧ�ĵ�һ���취
// ��base class�������ö���ǰ�� "this->:"

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
	this->sendClear(info); //����������sendClear���̳�
  }
};

#endif //INC_43_CMAKE_BUILD_DEBUG_DEMO1_HPP_
