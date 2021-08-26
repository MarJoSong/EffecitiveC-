#include <iostream>

//����43��ѧϰ����ģ�廯�����ڵ�����

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
	 * ���û��ຯ�������뱨��ԭ������
	 * LoggingMsgSender�̳���MsgSender<Company>����Company��һ��template����
	 * ��MsgSender<Company>��һ��ģ���࣬��Ȼ��ģ�壬�Ϳ��Զ�ģ������ػ�(���ػ���ȫ�ػ�)
	 * Ҳ���������һ��MsgSenderȫ�ػ����䲢���ṩSendClear��Ա������
	 * (��ʹ�������������ػ������Ǳ���������֪���䲻����)
	 * ����������ܾ���ģ�廯����(��������MsgSender<Company>)��Ѱ�Ҽ̳ж���������(SendClear)
	 */
	sendClear(info);
  }
};

//===================================================================

class CompanyZ {
 public:
  void sendEncrypted(const std::string &msg);
};
//Ҳ����ڣ�Ҳ�����ڵ�ȫ�ػ�ģ����
template<>
class MsgSender<CompanyZ> {
 public:
  void sendSecret(const MsgInfo &info) {};
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
