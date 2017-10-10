
// CopyRight Stephen Morrisson 2017
// All rights reserved.


#ifndef __CLIENT_CONNECTION__
#define  __CLIENT_CONNECTION__

#include <iostream>
#include <memory>
#include <stdio.h> //printf()
#include <vector>

#include "TwsCommonApp.h"
#include "ETWrapper.h"
#include "ETMessages.h"

//#include "PosixTestClient.h"


namespace TwsApp {

typedef enum 
  {
    RS_NONE,
    RS_SENT,
    RS_ACK,
  } RequestState;



class ClientConnection : public IB::ETWrapper {
  
 private:
  int iDebug;
  //  IB::PosixTestClient posixTestClient;
  int iClientId;
  bool bWasConnected; // result of last connection attemp
  ETMessages* pMessages;

  RequestState rsGetOrderId;

  int iOrderId;
  
 public:
  ClientConnection();

  virtual bool TryConnecting(unsigned uiAttempts, MyString sHost, int iPort, int iWaitInSec);
  virtual void Disconnect();

  virtual void RequestOrderId();

  virtual IB::OrderId PlaceOrder(ContractPtr pContract, OrderPtr pOrder);

  virtual void DB(int iLevel, MyString text);
  virtual void DB(int iLevel, MyString text, long v1);

 protected:
  // calls to repeated calls to listen, cause 508 error
  virtual void Listen();

 public: // from EWrapper (overriding from ETWrapper)

  virtual void error(const int id, const int errorCode, const IB::IBString errorString);
  virtual void managedAccounts( const IB::IBString& accountsList);
  virtual void nextValidId( IB::OrderId orderId);
  virtual void winError( const IB::IBString &str, int lastError);

};


}; // namespace

#endif //  __CLIENT_CONNECTION__

