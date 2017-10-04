
#include "ClientConnection.h"

using namespace std;
using namespace TwsApp;

ClientConnection::ClientConnection()
  : iDebug(100), bWasConnected(false)
{
}

bool ClientConnection::TryConnecting(unsigned uiAttempts, MyString sHost, int iPort)
{
  DB(90, "TryConnecting called");

  for (unsigned count = 0; count < uiAttempts; count++)
    {
      if (posixTestClient.connect( sHost, iPort, iClientId)) {
	bWasConnected = true;
	DB(100, "TryConnecting success");
	return true;
      }
    }
  DB(50, "TryConnecting failed");

  return false;
}

void ClientConnection::OldProcessMessages()
{
  for (int i = 0; i < 10; i++)
    {
      DB(0, "here");
      if (posixTestClient.isConnected())
	{
	  posixTestClient.processMessages();
	} else {
	DB(0, "isConnected failed");
      }
    }
}

void ClientConnection::Disconnect()
{
  if (posixTestClient.isConnected())
    {
      DB(90, "Disconnect called");
      posixTestClient.disconnect();
      DB(100, "Disconnect disconnected");
    } else {
    DB(50, "Disconnect was called when client was already disconnected");
  }
}


void ClientConnection::DB(int iLevel, MyString text)
{
  if (iLevel <= iDebug)
    {
      cout << "DB ClientConnection::" << text << endl;
    }
}

