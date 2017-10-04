
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
 private:
  int id;
};

typedef ETMessage* ETMessagePtr;
typedef std::queue<ETMessagePtr> MessageQueue;


class GetOrderIdMsg : public ETMessage {
 public:
  GetOrderIdMsg();
};

class PlaceOrderMsg : public ETMessage {
 private:
  int messageId;
  ContractPtr pContract;
  OrderPtr pOrder;
 public:
  PlaceOrderMsg(int messageId, ContractPtr pContract, OrderPtr pOrder);
};


class ETMessages {
 public:
  ETMessages();

  void EnqueueGetOrderId();
  int PlaceOrder(int messageId, ContractPtr pContract, OrderPtr pOrder);
 private:
  MessageQueue messages;

  int iDebug;
  void DB(int iLevel, MyString text);
  
};

#endif //  __ET_MESSAGES__
