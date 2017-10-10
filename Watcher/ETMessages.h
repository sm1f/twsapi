
// CopyRight Stephen Morrisson 2017
// All rights reserved.


#ifndef __ET_MESSAGES__
#define  __ET_MESSAGES__

#include <iostream>
#include <memory>
#include <vector>
#include <queue>

#include "TwsCommonApp.h"
#include "ETWrapper.h"

class ETMessage {
 private:
  static int iMessageCount;
 public:
  ETMessage();
  int GetId();

  virtual bool Send(std::shared_ptr<IB::EPosixClientSocket> pPosixClientSocket, struct timeval &tTimeout) = 0;
 private:
  int id;
};

typedef std::shared_ptr<ETMessage> ETMessagePtr;
typedef std::queue<ETMessagePtr> MessageQueue;


class GetOrderIdMsg : public ETMessage {
 public:
  GetOrderIdMsg();

  virtual bool Send(std::shared_ptr<IB::EPosixClientSocket> pPosixClientSocket, struct timeval &tTimeout);
};

class PlaceOrderMsg : public ETMessage {
 private:
  int messageId;
  ContractPtr pContract;
  OrderPtr pOrder;
 public:
  PlaceOrderMsg(int messageId, ContractPtr pContract, OrderPtr pOrder);

  virtual bool Send(std::shared_ptr<IB::EPosixClientSocket> pPosixClientSocket, struct timeval &tTimeout);
};


class ETMessages {
 public:
  ETMessages();

  void EnqueueGetOrderId();
  int PlaceOrder(int messageId, ContractPtr pContract, OrderPtr pOrder);

  bool TrySending(std::shared_ptr<IB::EPosixClientSocket> pPosixClientSocket, struct timeval &tTimeout);
 private:
  int iNextOrderId;  // assume zero at start.
  MessageQueue* qMessages;

  int iDebug;
  void DB(int iLevel, MyString text);
  void DB(int iLevel, MyString text, int iVal);
  
};

#endif //  __ET_MESSAGES__
