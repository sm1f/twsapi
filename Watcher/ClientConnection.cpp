// CopyRight Stephen Morrisson 2017
// All rights reserved.

#include <unistd.h>

#include "ClientConnection.h"

using namespace std;
using namespace TwsApp;



ClientConnection::ClientConnection()
  : iDebug(100), bWasConnected(false), pMessages(new ETMessages()),
    rsGetOrderId(RS_NONE)
{
}

bool ClientConnection::TryConnecting(unsigned uiAttempts, MyString sHost, int iPort, int iWaitInSec)
{
  DB(90, "TryConnecting called");

  for (unsigned count = 0; count < uiAttempts; count++)
    {
      if (m_pClient->eConnect2( sHost, iPort, iClientId)) {
	bWasConnected = true;
	DB(100, "TryConnecting success");

	THINK_ABOUT("if you don't wait, the connection does not work.");
	sleep(iWaitInSec);

	return true;
      }
    }
  DB(10, "TryConnecting failed");
  return false;
}

void ClientConnection::Disconnect()
{
  DB(90, "Disconnect called");
  m_pClient->eDisconnect();
  DB(500, "Disconnect disconnected");
}

void ClientConnection::RequestOrderId()
{
  DB(90, "ClientConnection::RequestOrderId() started.");
  m_pClient->reqIds(-1);
  DB(95, "ClientConnection::RequestOrderId() about to listen.");
  Listen();
  DB(500, "ClientConnection::RequestOrderId() done.");
}

void ClientConnection::Listen()
{
  DB(90, "ClientConnection::Listen() started.");
  m_pClient->onReceive();
  DB(500, "ClientConnection::Listen() done.");
}


void ClientConnection::DB(int iLevel, MyString text)
{
  if (iLevel <= iDebug)
    {
      cout << "DB ClientConnection::" << text << endl;
    }
}

