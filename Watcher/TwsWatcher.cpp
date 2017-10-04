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

  ClientConnection* oConn = new ClientConnection();

  unsigned max_attempts = 10;
  if (! oConn->TryConnecting(max_attempts, sHost, iPort))
    {
       cerr << "Error: TwsWatcher: connection failed" << endl << flush;
       return 1;
    }

  NYI("TwsWatcher.RunMain");

  int iOrderId = oConn->EnqueOrder();
  cout << "TwsWatcher enqued order with id: " << iOrderId << endl;


  struct timeval tSendReciveTimeout = {1,1};
  oConn->SendRecieve(tSendReciveTimeout);

  struct timeval tPlaceOrderTimeout = {1,1};
  oConn->PlaceOrder(tPlaceOrderTimeout);
  
  oConn->Listen();
  
  oConn->Disconnect();
  
  return 0;
}


void TwsWatcher::DB(int level, MyString text)
{
  if (level <= iDebugWatcher)
    {
      cout << "DB Watcher: " << text << endl;
    }
}
