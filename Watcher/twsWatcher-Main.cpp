// CopyRight Stephen Morrisson 2017
// All rights reserved.



#include <stdio.h>
#include <iostream>

#include "TwsWatcher.h"

const unsigned MAX_ATTEMPTS = 1;
const unsigned SLEEP_TIME = 10;

using namespace std;

using namespace TwsApp;

int main(int argc, const char** argv)
{
#if 0
  TwsWatcher that(argc, argv);
  //  that.SetGeneralDebugLevel(100);

  int result = that.RunMain();

  if (result != 0)
    {
      cout << endl << "TwsWatcher returned: " << result << endl;
    }

  return result;
#endif // 0
  return -1;
}

#if 0
  
	const char* host = argc > 1 ? argv[1] : "";
	unsigned int port = argc > 2 ? atoi(argv[2]) : 7496;
	int clientId = 0;

	unsigned attempt = 0;
	printf( "Start of POSIX Socket Client Test %u\n", attempt);

	for (;;) {
		++attempt;
		printf( "Attempt %u of %u\n", attempt, MAX_ATTEMPTS);

		IB::PosixTestClient client;

		client.connect( host, port, clientId);

		while( client.isConnected()) {
			client.processMessages();
		}

		if( attempt >= MAX_ATTEMPTS) {
			break;
		}

		printf( "Sleeping %u seconds before next attempt\n", SLEEP_TIME);
		sleep( SLEEP_TIME);
	}

	printf ( "End of POSIX Socket Client Test\n");

#endif // 0
