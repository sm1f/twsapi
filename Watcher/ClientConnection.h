

#ifndef __CLIENT_CONNECTION__
#define  __CLIENT_CONNECTION__

#include <iostream>

#include "TwsCommonApp.h"
#include "PosixTestClient.h"


class ClientConnection {
 private:
  int iDebug;
  IB::PosixTestClient posixTestClient;
  int iClientId;
  bool bWasConnected; // result of last connection attemp
  
 public:
  ClientConnection();

  virtual bool TryConnecting(unsigned uiAttempts, TwsApp::MyString sHost, int iPort);
  virtual void Disconnect();

  // hack
  void OldProcessMessages();

  virtual void DB(int iLevel, TwsApp::MyString text);
};

#endif //  __CLIENT_CONNECTION__

