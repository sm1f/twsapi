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
{
}

#define NYI(FN) { std::cout << "ETWrapper::" << FN << std::endl; }

  void ETWrapper::tickPrice( TickerId tickerId, TickType field, double price, int canAutoExecute)
{ NYI("tickPrice"); }
  
   void ETWrapper::tickSize( TickerId tickerId, TickType field, int size) { NYI("??"); }
   void ETWrapper::tickOptionComputation( TickerId tickerId, TickType tickType, double impliedVol, double delta,
	   double optPrice, double pvDividend, double gamma, double vega, double theta, double undPrice) { NYI("??"); }
   void ETWrapper::tickGeneric(TickerId tickerId, TickType tickType, double value) { NYI("??"); }
   void ETWrapper::tickString(TickerId tickerId, TickType tickType, const IBString& value) { NYI("??"); }
   void ETWrapper::tickEFP(TickerId tickerId, TickType tickType, double basisPoints, const IBString& formattedBasisPoints,
	   double totalDividends, int holdDays, const IBString& futureExpiry, double dividendImpact, double dividendsToExpiry) { NYI("??"); }
   void ETWrapper::orderStatus( OrderId orderId, const IBString &status, int filled,
	   int remaining, double avgFillPrice, int permId, int parentId,
	   double lastFillPrice, int clientId, const IBString& whyHeld) { NYI("??"); }
   void ETWrapper::openOrder( OrderId orderId, const Contract&, const Order&, const OrderState&) { NYI("??"); }
   void ETWrapper::openOrderEnd() { NYI("??"); }
   void ETWrapper::winError( const IBString &str, int lastError) { NYI("??"); }
   void ETWrapper::connectionClosed() { NYI("??"); }
   void ETWrapper::updateAccountValue(const IBString& key, const IBString& val,
				      const IBString& currency, const IBString& accountName) { NYI("??"); }
   void ETWrapper::updatePortfolio( const Contract& contract, int position,
      double marketPrice, double marketValue, double averageCost,
      double unrealizedPNL, double realizedPNL, const IBString& accountName) { NYI("??"); }
   void ETWrapper::updateAccountTime(const IBString& timeStamp) { NYI("??"); }
   void ETWrapper::accountDownloadEnd(const IBString& accountName) { NYI("??"); }
   void ETWrapper::nextValidId( OrderId orderId) { NYI("??"); }
   void ETWrapper::contractDetails( int reqId, const ContractDetails& contractDetails) { NYI("??"); }
   void ETWrapper::bondContractDetails( int reqId, const ContractDetails& contractDetails) { NYI("??"); }
   void ETWrapper::contractDetailsEnd( int reqId) { NYI("??"); }
   void ETWrapper::execDetails( int reqId, const Contract& contract, const Execution& execution) { NYI("??"); }
   void ETWrapper::execDetailsEnd( int reqId) { NYI("??"); }
   void ETWrapper::error(const int id, const int errorCode, const IBString errorString) { NYI("??"); }
   void ETWrapper::updateMktDepth(TickerId id, int position, int operation, int side,
      double price, int size) { NYI("??"); }
   void ETWrapper::updateMktDepthL2(TickerId id, int position, IBString marketMaker, int operation,
      int side, double price, int size) { NYI("??"); }
   void ETWrapper::updateNewsBulletin(int msgId, int msgType, const IBString& newsMessage, const IBString& originExch) { NYI("??"); }
   void ETWrapper::managedAccounts( const IBString& accountsList) { NYI("??"); }
   void ETWrapper::receiveFA(faDataType pFaDataType, const IBString& cxml) { NYI("??"); }
   void ETWrapper::historicalData(TickerId reqId, const IBString& date, double open, double high, 
	   double low, double close, int volume, int barCount, double WAP, int hasGaps) { NYI("??"); }
   void ETWrapper::scannerParameters(const IBString &xml) { NYI("??"); }
   void ETWrapper::scannerData(int reqId, int rank, const ContractDetails &contractDetails,
	   const IBString &distance, const IBString &benchmark, const IBString &projection,
	   const IBString &legsStr) { NYI("??"); }
   void ETWrapper::scannerDataEnd(int reqId) { NYI("??"); }
   void ETWrapper::realtimeBar(TickerId reqId, long time, double open, double high, double low, double close,
	   long volume, double wap, int count) { NYI("??"); }
   void ETWrapper::currentTime(long time) { NYI("??"); }
   void ETWrapper::fundamentalData(TickerId reqId, const IBString& data) { NYI("??"); }
   void ETWrapper::deltaNeutralValidation(int reqId, const UnderComp& underComp) { NYI("??"); }
   void ETWrapper::tickSnapshotEnd( int reqId) { NYI("??"); }
   void ETWrapper::marketDataType( TickerId reqId, int marketDataType) { NYI("??"); }
   void ETWrapper::commissionReport( const CommissionReport &commissionReport) { NYI("??"); }
   void ETWrapper::position( const IBString& account, const Contract& contract, int position, double avgCost) { NYI("??"); }
   void ETWrapper::positionEnd() { NYI("??"); }
   void ETWrapper::accountSummary( int reqId, const IBString& account, const IBString& tag, const IBString& value, const IBString& curency) { NYI("??"); }
   void ETWrapper::accountSummaryEnd( int reqId) { NYI("??"); }
   void ETWrapper::verifyMessageAPI( const IBString& apiData) { NYI("??"); }
   void ETWrapper::verifyCompleted( bool isSuccessful, const IBString& errorText) { NYI("??"); }
   void ETWrapper::displayGroupList( int reqId, const IBString& groups) { NYI("??"); }
   void ETWrapper::displayGroupUpdated( int reqId, const IBString& contractInfo) { NYI("??"); }

  
}; // namespace IB


