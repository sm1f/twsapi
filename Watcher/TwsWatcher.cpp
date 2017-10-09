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
