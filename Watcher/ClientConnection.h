

#ifndef __CLIENT_CONNECTION__
#define  __CLIENT_CONNECTION__

#include <iostream>

#include "TwsCommonApp.h"
#include "PosixTestClient.h"


class ClientConnection {
 public:
  ClientConnection();

  virtual bool TryConnecting(unsigned uiAttempts);
  
};

#endif //  __CLIENT_CONNECTION__

