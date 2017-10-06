// CopyRight Stephen Morrisson 2017
// All rights reserved.

#include <iostream>
// needed for printf
#include <stdio.h>

#ifdef _WIN32
# include <windows.h>
# define SLEEP( seconds) Sleep( seconds * 1000);
#else
# include <unistd.h>
#endif


#include "TwsWatcher.h"

//#include "PosixTestClient.h"

using namespace std;
using namespace TwsApp;

TwsWatcher::TwsWatcher(int iArgCount, const char** asArgs)
  : TwsCommonApp(iArgCount, asArgs),
    iDebugWatcher(100),
    sHost(""), iPort(7496)
{

}

int TwsWatcher::RunMain()
{

  ClientConnection* pConn = new ClientConnection();
  int iWaitInSec = 2;
  struct timeval tTimeout = { iWaitInSec, 0};

  unsigned max_attempts = 10;
  if (! pConn->TryConnecting(max_attempts, sHost, iPort))
    {
       cerr << "Error: TwsWatcher: connection failed" << endl << flush;
       return 1;
    }

  NYI("About to sleep.");
  sleep(iWaitInSec);
  NYI("done sleeping.");
  pConn->TryRecieving(tTimeout);

  NYI("About to sleep.");
  sleep(iWaitInSec);
  NYI("done sleeping.");

  int iNextId = pConn->EnqueueGetOrderId(iWaitInSec);

  NYI("About to sleep.");
  sleep(iWaitInSec);
  NYI("done sleeping.");

  pConn->TryRecieving(tTimeout);
  
  NYI("TwsWatcher.RunMain");

  if (iNextId < 0)
    {
      cout << "EnqueueGetOrderId(iWaitInSec) returned neg id: " << iNextId << endl;
      return -1;
    }
  
  int iOrderId = pConn->EnqueOrder();
  cout << "TwsWatcher enqued order with id: " << iOrderId << endl;


  struct timeval tSendReciveTimeout = {1,1};
  pConn->SendRecieve(tSendReciveTimeout);

  struct timeval tPlaceOrderTimeout = {1,1};
  pConn->PlaceOrder(tPlaceOrderTimeout);
  
  pConn->Listen();
  
  pConn->Disconnect();
  
  return 0;
}


void TwsWatcher::DB(int level, MyString text)
{
  if (level <= iDebugWatcher)
    {
      cout << "DB Watcher: " << text << endl;
    }
}
