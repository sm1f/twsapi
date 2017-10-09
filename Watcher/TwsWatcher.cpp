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

void TwsWatcher::AddTwsWatcherArgs()
{
}


int TwsWatcher::RunMain()
{
  AddTwsWatcherArgs();
  if (! ParseArgs())
    {
      cout << "Parse Args failed!!!" << endl;
      return -1;
    }
  
  ClientConnection* pConn = new ClientConnection();
  int iWaitInSec = 3;
  struct timeval tTimeout = { iWaitInSec, 0};

  unsigned max_attempts = 10;
  if (! pConn->TryConnecting(max_attempts, sHost, iPort, iWaitInSec))
    {
       cerr << "Error: TwsWatcher: connection failed" << endl << flush;
       return 1;
    }

  DB(10, "Connected... request order id.");
  pConn->RequestOrderId();

  DB(10, "PlaceOrder...");
  ContractPtr pContract = std::make_shared<IB::Contract>();
  pContract->symbol = "IBM";
  pContract->secType = "STK";
  pContract->exchange = "SMART";
  pContract->currency = "USD";

  OrderPtr pOrder = std::make_shared<IB::Order>();
  pOrder->action = "BUY";
  pOrder->totalQuantity = 1000;
  pOrder->orderType = "LMT";
  pOrder->lmtPrice = 0.01;

  
  IB::OrderId orderId = pConn->PlaceOrder(pContract, pOrder);
  
  DB(10, "About to disconnect.");
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
