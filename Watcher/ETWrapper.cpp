// CopyRight Stephen Morrisson 2017
// All rights reserved.

#include <time.h>
#include <sys/time.h>
#include <stdio.h>

#include "ETWrapper.h"

#include "EPosixClientSocket.h"
#include "EPosixClientSocketPlatform.h"

#include "Contract.h"
#include "Order.h"

using namespace std;

namespace IB {

ETWrapper::ETWrapper()
  : EWrapper(), m_pClient(new EPosixClientSocket(this))
{
}

#define NYI(FN) { std::cout << "ETWrapper::" << FN << std::endl; }

  void ETWrapper::tickPrice( TickerId tickerId, TickType field, double price, int canAutoExecute)
{ NYI("tickPrice"); }
  
   void ETWrapper::tickSize( TickerId tickerId, TickType field, int size) { NYI("??tickSize"); }
   void ETWrapper::tickOptionComputation( TickerId tickerId, TickType tickType, double impliedVol, double delta,
	   double optPrice, double pvDividend, double gamma, double vega, double theta, double undPrice) { NYI("??double"); }
   void ETWrapper::tickGeneric(TickerId tickerId, TickType tickType, double value) { NYI("??tickGeneric"); }
   void ETWrapper::tickString(TickerId tickerId, TickType tickType, const IBString& value) { NYI("??tickString"); }
   void ETWrapper::tickEFP(TickerId tickerId, TickType tickType, double basisPoints, const IBString& formattedBasisPoints,
	   double totalDividends, int holdDays, const IBString& futureExpiry, double dividendImpact, double dividendsToExpiry) { NYI("??int"); }
   void ETWrapper::orderStatus( OrderId orderId, const IBString &status, int filled,
	   int remaining, double avgFillPrice, int permId, int parentId,
	   double lastFillPrice, int clientId, const IBString& whyHeld) { NYI("??orderStatus"); }
   void ETWrapper::openOrder( OrderId orderId, const Contract&, const Order&, const OrderState&) { NYI("??openOrder"); }
   void ETWrapper::openOrderEnd() { NYI("??openOrderEnd"); }

  void ETWrapper::winError( const IBString &str, int lastError)
  {
    cout << "ETWrapper::winError( const IBString &str, int lastError) str: " << str << " lastError: " << lastError << endl; 
  }
   void ETWrapper::connectionClosed() { NYI("??connectionClosed"); }
   void ETWrapper::updateAccountValue(const IBString& key, const IBString& val,
				      const IBString& currency, const IBString& accountName) { NYI("??currency"); }
   void ETWrapper::updatePortfolio( const Contract& contract, int position,
      double marketPrice, double marketValue, double averageCost,
      double unrealizedPNL, double realizedPNL, const IBString& accountName) { NYI("??updatePortfolio"); }
   void ETWrapper::updateAccountTime(const IBString& timeStamp) { NYI("??updateAccountTime"); }
   void ETWrapper::accountDownloadEnd(const IBString& accountName) { NYI("??accountDownloadEnd"); }

  void ETWrapper::nextValidId( OrderId orderId)
  {
    NYI("??nextValidId");
    cout << "ETWrapper::nextValidId( OrderId orderId): " << orderId << endl;
  }
   void ETWrapper::contractDetails( int reqId, const ContractDetails& contractDetails) { NYI("??contractDetails"); }
   void ETWrapper::bondContractDetails( int reqId, const ContractDetails& contractDetails) { NYI("??bondContractDetails"); }
   void ETWrapper::contractDetailsEnd( int reqId) { NYI("??contractDetailsEnd"); }
   void ETWrapper::execDetails( int reqId, const Contract& contract, const Execution& execution) { NYI("??execDetails"); }
   void ETWrapper::execDetailsEnd( int reqId) { NYI("??execDetailsEnd"); }

  void ETWrapper::error(const int id, const int errorCode, const IBString errorString)
  {
    cout << "ETWrapper::error(const int id, const int errorCode, const IBString errorString)"
	 << "  id: " << id << "  errorCode: " << errorCode << "  errorString: " << errorString << endl;
  }

  void ETWrapper::updateMktDepth(TickerId id, int position, int operation, int side,
      double price, int size) { NYI("??updateMktDepth"); }
   void ETWrapper::updateMktDepthL2(TickerId id, int position, IBString marketMaker, int operation,
      int side, double price, int size) { NYI("??updateMktDepthL2"); }
   void ETWrapper::updateNewsBulletin(int msgId, int msgType, const IBString& newsMessage, const IBString& originExch) { NYI("??updateNewsBulletin"); }

  void ETWrapper::managedAccounts( const IBString& accountsList)
  {
    NYI("??managedAccounts");
    cout << "ETWrapper::managedAccounts( const IBString& accountsList) " << accountsList << endl;
  }


  void ETWrapper::receiveFA(faDataType pFaDataType, const IBString& cxml) { NYI("??receiveFA"); }
   void ETWrapper::historicalData(TickerId reqId, const IBString& date, double open, double high, 
	   double low, double close, int volume, int barCount, double WAP, int hasGaps) { NYI("??double"); }
   void ETWrapper::scannerParameters(const IBString &xml) { NYI("??scannerParameters"); }
   void ETWrapper::scannerData(int reqId, int rank, const ContractDetails &contractDetails,
	   const IBString &distance, const IBString &benchmark, const IBString &projection,
	   const IBString &legsStr) { NYI("??scannerData"); }
   void ETWrapper::scannerDataEnd(int reqId) { NYI("??scannerDataEnd"); }
   void ETWrapper::realtimeBar(TickerId reqId, long time, double open, double high, double low, double close,
	   long volume, double wap, int count) { NYI("??realtimeBar"); }
   void ETWrapper::currentTime(long time) { NYI("??currentTime"); }
   void ETWrapper::fundamentalData(TickerId reqId, const IBString& data) { NYI("??fundamentalData"); }
   void ETWrapper::deltaNeutralValidation(int reqId, const UnderComp& underComp) { NYI("??deltaNeutralValidation"); }
   void ETWrapper::tickSnapshotEnd( int reqId) { NYI("??tickSnapshotEnd"); }
   void ETWrapper::marketDataType( TickerId reqId, int marketDataType) { NYI("??marketDataType"); }
   void ETWrapper::commissionReport( const CommissionReport &commissionReport) { NYI("??commissionReport"); }
   void ETWrapper::position( const IBString& account, const Contract& contract, int position, double avgCost) { NYI("??position"); }
   void ETWrapper::positionEnd() { NYI("??positionEnd"); }
   void ETWrapper::accountSummary( int reqId, const IBString& account, const IBString& tag, const IBString& value, const IBString& curency) { NYI("??accountSummaryaccountSummary"); }
   void ETWrapper::accountSummaryEnd( int reqId) { NYI("??accountSummaryEnd"); }
   void ETWrapper::verifyMessageAPI( const IBString& apiData) { NYI("??verifyMessageAPI"); }
   void ETWrapper::verifyCompleted( bool isSuccessful, const IBString& errorText) { NYI("??verifyCompleted"); }
   void ETWrapper::displayGroupList( int reqId, const IBString& groups) { NYI("??displayGroupList"); }
   void ETWrapper::displayGroupUpdated( int reqId, const IBString& contractInfo) { NYI("??displayGroupUpdated"); }

  
}; // namespace IB


