//
// Created by mars on 2021/8/26.
//

#ifndef INC_43__DEMO3_HPP_
#define INC_43__DEMO3_HPP_

// ��C++ "������templatized base classes�۲�" ����ΪʧЧ�ĵ������취
// ��ȷָ�������õĺ���λ�ڻ�����MsgSender<Company>::sendClear(info)
// ��������õ���virtual�������ᵼ�¶�̬������ʧЧ


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
	MsgSender<Company>::sendClear(info); //������sendClear���̳�
  }
};

#endif //INC_43__DEMO3_HPP_
