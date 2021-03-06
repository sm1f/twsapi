/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#ifdef _WIN32
#include <windows.h>
#define SLEEP( seconds) Sleep( seconds * 1000);
#else
#include <unistd.h>
#define SLEEP( seconds) sleep( seconds);
#endif

#include <stdio.h>

#include "PosixTestClient.h"

const unsigned MAX_ATTEMPTS = 1;
const unsigned SLEEP_TIME = 10;

int main(int argc, char** argv)
{
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
		  SLEEP(1);
			client.processMessages();
		}

		if( attempt >= MAX_ATTEMPTS) {
			break;
		}

		printf( "Sleeping %u seconds before next attempt\n", SLEEP_TIME);
		SLEEP( SLEEP_TIME);
	}

	printf ( "End of POSIX Socket Client Test\n");
}

