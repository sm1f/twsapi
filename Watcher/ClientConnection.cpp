
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
      if (posixTextClient.connect( sHost, iPort, iClientId)) {
	bWasConnected = true;
	DB(100, "TryConnecting success");
	return true;
      }
    }
  DB(50, "TryConnecting failed");

  return false;
}


void ClientConnection::DB(int iLevel, MyString text)
{
  if (iLevel <= iDebug)
    {
      cout << "DB ClientConnection::" << text << endl;
    }
}
