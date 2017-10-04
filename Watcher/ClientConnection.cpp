// CopyRight Stephen Morrisson 2017
// All rights reserved.

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
      if (m_pClient->eConnect2( sHost, iPort, iClientId)) {
	bWasConnected = true;
	DB(100, "TryConnecting success");
	return true;
      }
    }
  DB(50, "TryConnecting failed");
  return false;
}

void ClientConnection::Listen()
{
  DB(90, "ClientConnection::Listen() start");

  if (m_pClient->fd() < 0)
    {
      DB(80, "ClientConnection::Listen() fd less then 0");
      return;
    }

  struct timeval tTimeout;
  tTimeout.tv_usec = 0;
  tTimeout.tv_sec = 0;

  fd_set readSet, writeSet, expSet;
  FD_ZERO(&readSet);
  FD_ZERO(&writeSet);
  FD_ZERO(&expSet);
  FD_SET(m_pClient->fd(), &readSet);
  FD_SET(m_pClient->fd(), &writeSet);
  FD_SET(m_pClient->fd(), &expSet);

  int iSelectResult = select( m_pClient->fd() + 1, &readSet, &writeSet, &expSet, &tTimeout);
  
  if (FD_ISSET(m_pClient->fd(), &readSet))
    {
      DB(10, "ClientConnection::Listen() FD_ISSET readset is true");
    } else
    {
      DB(10, "ClientConnection::Listen() FD_ISSET readset is false");
    }

  if (FD_ISSET(m_pClient->fd(), &writeSet))
    {
      DB(10, "ClientConnection::Listen() FD_ISSET writeset is true");
    } else
    {
      DB(10, "ClientConnection::Listen() FD_ISSET writeset is false");
    }

  if (FD_ISSET(m_pClient->fd(), &expSet))
    {
      DB(10, "ClientConnection::Listen() FD_ISSET expset is true");
    } else
    {
      DB(10, "ClientConnection::Listen() FD_ISSET expset is false");
    }
  
  DB(90, "ClientConnection::Listen() end");
}

int ClientConnection::EnqueOrder()
{
  NYI("ClientConnection::EnqueOrder()");
  return -1;
}


void ClientConnection::SendRecieve(struct timeval &tTimeout)
{
  DB(90, "ClientConnection::SendRecieve() start");

  if (m_pClient->fd() < 0)
    {
      DB(80, "ClientConnection::SendRecieve() fd less then 0");
      return;
    }

  fd_set readSet, writeSet, expSet;
  FD_ZERO(&readSet);
  FD_ZERO(&writeSet);
  FD_ZERO(&expSet);
  FD_SET(m_pClient->fd(), &readSet);
  FD_SET(m_pClient->fd(), &writeSet);
  FD_SET(m_pClient->fd(), &expSet);

  int iSelectResult = select( m_pClient->fd() + 1, &readSet, &writeSet, &expSet, &tTimeout);
  
  if (FD_ISSET(m_pClient->fd(), &expSet))
    {
      DB(10, "ClientConnection::SendRecieve() FD_ISSET expset is true");
    } else
    {
      DB(10, "ClientConnection::SendRecieve() FD_ISSET expset is false");
    }

  if (FD_ISSET(m_pClient->fd(), &readSet))
    {
      TryRecieving();
    }

  if (FD_ISSET(m_pClient->fd(), &writeSet))
    {
      DB(10, "ClientConnection::SendRecieve() FD_ISSET writeset is true");
    } else
    {
      DB(10, "ClientConnection::SendRecieve() FD_ISSET writeset is false");
    }

  
  DB(90, "ClientConnection::SendRecieve() end");
}

void ClientConnection::TryRecieving()
{
  NYI("ClientConnection::TryRecivieving()");
}

bool ClientConnection::TrySending(struct timeval &tTimeout)
{
  NYI("ClientConnection::TrySending()");
  return false;
}


int ClientConnection::EnqueueGetOrderId(int iTimeoutInSec)
{
  DB(90, "ClientConnection::EnqueueGetOrderId(int iTimeoutInSec)");
  oMessages.EnqueueGetOrderId();

  struct timeval tTimeout = { iTimeoutInSec, 0};
  while (TrySending(tTimeout)) {
    DB(100, "TrySending returned true, trying to send more");
  }
  NYI("ClientConnection::EnqueueGetOrderId(int iTimeoutInSec)");
  return -1;
}


int ClientConnection::PlaceOrder(struct timeval &tTimeout)
{
  DB(90, "ClientConnection::PlaceOrder()");
  NYI("ClientConnection::PlaceOrder(struct timeval &tTimeout)");
  int iResult = -1;
  //int iResult = oMessages.PlaceOrder();
  //  if (! TrySending(tTimeout)) {
  //    DB(50, "ClientConnection::PlaceOrder TrySending failed.");
  //  }
  
  return iResult;
}


void ClientConnection::Disconnect()
{
  DB(90, "Disconnect called");
  m_pClient->eDisconnect();
  DB(500, "Disconnect disconnected");
}

void ClientConnection::SetContract(ContractPtr pContract, MyString sSymbol, MyString sSecType, MyString sExchange, MyString sCurrency)
{
  pContract->symbol = sSymbol;
  pContract->secType = sSecType;
  pContract->exchange = sExchange;
  pContract->currency = sCurrency;
}

void ClientConnection::SetOrder(OrderPtr pOrder, MyString sAction, int iQuantity, MyString sOrderType, float fPrice)
{
  pOrder->action = sAction;
  pOrder->totalQuantity = iQuantity;
  pOrder->orderType = sOrderType;
  THINK_ABOUT("my want to change this to dollors and cents.");
  pOrder->lmtPrice = fPrice;  
}



void ClientConnection::DB(int iLevel, MyString text)
{
  if (iLevel <= iDebug)
    {
      cout << "DB ClientConnection::" << text << endl;
    }
}

