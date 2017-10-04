
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




class ClientConnection : public IB::ETWrapper {

 private:
  int iDebug;
  //  IB::PosixTestClient posixTestClient;
  int iClientId;
  bool bWasConnected; // result of last connection attemp
  ETMessages oMessages;
  
 public:
  ClientConnection();

  virtual bool TryConnecting(unsigned uiAttempts, MyString sHost, int iPort);
  virtual void Disconnect();

  virtual void Listen();

  virtual int EnqueOrder();
  virtual void SendRecieve(struct timeval &tTimeout);
  virtual void TryRecieving();
  virtual bool TrySending(struct timeval &tTimeout);
  
  virtual int PlaceOrder(struct timeval &tTimeout);

  // util fuctions
  virtual void SetContract(ContractPtr pContract, MyString sSymbol, MyString sSecType, MyString sExchange, MyString sCurrency);
  virtual void SetOrder(OrderPtr pOrder, MyString sAction, int iQuantity, MyString sOrderType, float fPrice);
  
  virtual void DB(int iLevel, MyString text);

};


  //};

#endif //  __CLIENT_CONNECTION__

