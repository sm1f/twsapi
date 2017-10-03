
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
  : TwsCommonApp(iArgCount, asArgs), iDebugWatcher(100),
    iPort(7496), sHost("")
{

}

int TwsWatcher::RunMain()
{

  NYI("TwsWatcher.RunMain");
  ClientConnection oConn;

  unsigned max_attempts = 10;
  if (oConn.TryConnecting(max_attempts))
    {
    } else
    {
      cerr << "Error: TwsWatcher: connection failed" << endl << flush;
    }
#if 0
	unsigned attempt = 0;
	
	printf( "Start of POSIX Socket Client Test %u\n", attempt);

	
	
	for (;;) {
		++attempt;
		printf( "Attempt %u of %u\n", attempt, max_attempts);

		int clientId = 0;
		IB::PosixTestClient client;

		client.connect( sHost, iPort, clientId);

		while( client.isConnected()) {
			client.processMessages();
		}

		if( attempt >= max_attempts) {
			break;
		}

		printf( "Sleeping %u seconds before next attempt\n", 1000);
		sleep( 1000);
	}

	printf ( "End of POSIX Socket Client Test\n");
#endif // 0
  return 0;
}


void TwsWatcher::DB(int level, MyString text)
{
  if (level <= iDebugWatcher)
    {
      cout << "DB Watcher: " << text << endl;
    }
}
