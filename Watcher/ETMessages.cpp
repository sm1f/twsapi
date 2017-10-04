// CopyRight Stephen Morrisson 2017
// All rights reserved.


#include "ETMessages.h"

using namespace std;


int ETMessage::iMessageCount = 0;

ETMessage::ETMessage()
  : id(iMessageCount++)
{
}


ETMessages::ETMessages()
  : iDebug(100)
{
}

PlaceOrderMsg::PlaceOrderMsg(int messageId, ContractPtr pContract, OrderPtr pOrder)
{
  this->messageId = messageId;
  this->pContract = pContract;
  this->pOrder = pOrder;
}

int ETMessages::PlaceOrder(int messageId, ContractPtr pContract, OrderPtr pOrder)
{
  DB(90, "ETMessages::PlaceOrder()");
  PlaceOrderMsg* msg = new PlaceOrderMsg(messageId, pContract, pOrder);

  messages.push(msg);
  return messageId;
  
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


void ETMessages::DB(int iLevel, MyString text)
{
  if (iLevel <= iDebug)
    {
      cout << "DB ETMessages::" << text << endl;
    }
}

