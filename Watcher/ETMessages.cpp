// CopyRight Stephen Morrisson 2017
// All rights reserved.


#include "ETMessages.h"

using namespace std;


/** ET Message ************************/
int ETMessage::iMessageCount = 0;

ETMessage::ETMessage()
  : id(iMessageCount++)
{
}

/** Get Order Id Msg *******************/
GetOrderIdMsg::GetOrderIdMsg()
{
}

bool GetOrderIdMsg::Send(std::shared_ptr<IB::EPosixClientSocket> pPosixClientSocket, struct timeval &tTimeout)
{
  pPosixClientSocket->reqIds(-1);
  return true;
}



/** Place Order Msg *******************/


PlaceOrderMsg::PlaceOrderMsg(int messageId, ContractPtr pContract, OrderPtr pOrder)
{
  this->messageId = messageId;
  this->pContract = pContract;
  this->pOrder = pOrder;
}

bool PlaceOrderMsg::Send(std::shared_ptr<IB::EPosixClientSocket> pPosixClientSocket, struct timeval &tTimeout)
{
  NYI("PlaceOrderMsg::Send(std::shared_ptr<IB::EPosixClientSocket> pPosixClientSocket, struct timeval &tTimeout)");
  return false;
}


/**  ET MESSAGES  ********************************/

ETMessages::ETMessages()
  : iNextOrderId(0), qMessages(new MessageQueue()), iDebug(100)
{
  THINK_ABOUT("next order id.  Comments say can assume zero unless... but set with reqIds");
}

void ETMessages::EnqueueGetOrderId()
{
  DB(0, "ETMessages::EnqueueGetOrderId() start");

  std::shared_ptr<GetOrderIdMsg> msg = std::make_unique<GetOrderIdMsg>();
  qMessages->push(msg);

  DB(0, "ETMessages::EnqueueGetOrderId() end");
}


int ETMessages::PlaceOrder(int messageId, ContractPtr pContract, OrderPtr pOrder)
{
  DB(90, "ETMessages::PlaceOrder()");
  std::shared_ptr<PlaceOrderMsg> msg = std::make_unique<PlaceOrderMsg>(messageId, pContract, pOrder);

  qMessages->push(msg);
  return messageId;

  NYI("ETMessages::PlaceOrder(int messageId, ContractPtr pContract, OrderPtr pOrder)");
  #if 0
    printf("placeOrder Called.\n");
	Contract contract;
	Order order;

	contract.symbol = "IBM";
	contract.secType = "STK";
	contract.exchange = "SMART";
	contract.currency = "USD";

	order.action = "BUY";
	order.totalQuantity = 1000;
	order.orderType = "LMT";
	order.lmtPrice = 0.01;

	printf( "Placing Order %ld: %s %ld %s at %f\n", m_orderId, order.action.c_str(), order.totalQuantity, contract.symbol.c_str(), order.lmtPrice);

	m_state = ST_PLACEORDER_ACK;
	printf("ZZ placeOrder(): %d\n", m_state);
	
	m_pClient->placeOrder( m_orderId, contract, order);
#endif // 0
}

bool ETMessages::TrySending(std::shared_ptr<IB::EPosixClientSocket> pPosixClientSocket, struct timeval &tTimeout)
{
  DB(90, "ETMessages::TrySending  queue size:", qMessages->size());

  if (!qMessages->empty())
    {
      ETMessagePtr pMsg = qMessages->front();
      bool result = pMsg->Send(pPosixClientSocket, tTimeout);
      
      qMessages->pop();
      return result;
    }
  
  DB(90, "ETMessages::TrySending done queue size:", qMessages->size());
  return false;
}



void ETMessages::DB(int iLevel, MyString text)
{
  if (iLevel <= iDebug)
    {
      cout << "DB ETMessages::" << text << endl;
    }
}

void ETMessages::DB(int iLevel, MyString text, int iVal)
{
  if (iLevel <= iDebug)
    {
      cout << "DB ETMessages::" << text << " " << iVal << endl;
    }
}

