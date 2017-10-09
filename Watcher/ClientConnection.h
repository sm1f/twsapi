
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

  virtual void DB(int iLevel, MyString text);

 protected:
  // calls to repeated calls to listen, cause 508 error
  virtual void Listen();

};


  //};

#endif //  __CLIENT_CONNECTION__

