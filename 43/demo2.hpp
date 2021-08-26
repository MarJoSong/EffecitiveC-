//
// Created by mars on 2021/8/26.
//

#ifndef INC_43__DEMO2_HPP_
#define INC_43__DEMO2_HPP_

// ��C++ "������templatized base classes�۲�" ����ΪʧЧ�ĵڶ����취
// ʹ��using����ʽ�� "���ڸǵĻ�������" ����һ����������������
// ������ʵ���ǻ������Ʊ����ڣ����Ǳ�����������������������

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
  //���߱����������� �����衱 sendClearλ�ڻ�����
  using MsgSender<Company>::sendClear;
  void sendClearMsg(const MsgInfo& info) {
	sendClear(info); //������sendClear���̳�
  }
};

#endif //INC_43__DEMO2_HPP_
