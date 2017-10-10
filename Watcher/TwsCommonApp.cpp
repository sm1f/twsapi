// CopyRight Stephen Morrisson 2017
// All rights reserved.

#include <algorithm>

#include "TwsCommonApp.h"
#include "ClientConnection.h"

using namespace std;
using namespace TwsApp;

/** CommandLineDatum *************************/
CommandLineDatum::CommandLineDatum(MyString sShort, MyString sFull)
  : sShortName(sShort), sFullName(sFull)
{
}


/** CommandLineInt ****************************/

CommandLineInt::CommandLineInt(MyString sShort, MyString sFull, int* piVarIn)
  : CommandLineDatum(sShort, sFull), piVar(piVarIn)
{
}


/** CommandLineData *************************/

CommandLineData::CommandLineData(int iArgCountIn, const char** asArgsIn)
  : iArgCount(iArgCountIn), asArgs(asArgsIn)
{
}

bool CommandLineData::ParseArgs()
{
  return false;
}

void CommandLineData::AddIntArg(const char* sShortName, const char* sFullName, int* piInt)
{
  CommandLineInt* that = new CommandLineInt(sShortName, sFullName, piInt);
  vArgData.push_back(that);
  mShortName2Datum[sShortName] = that;
  mFullName2Datum[sFullName] = that;
}

void CommandLineData::DumpArgs(MyString sTitle)
{
  if (sTitle != NULL)
    {
      cout << "" << sTitle << endl;
    }
  for (int i = 0; i < iArgCount; i++)
    {
      cout << "Arg [" << i << "]" << asArgs[i] << endl;
    }
}

void StaticDumpData(std::pair<const MyString, CommandLineDatumPtr>& pair)
{
    NYI("StaticDumpData(std::pair<MyString, CommandLineDatumPtr>& pair): ");
}

void CommandLineData::DumpData(MyString sTitle)
{
  if (sTitle != NULL)
    {
      cout << "" << sTitle << endl;
    }
  for (Name2CLDatumMap::iterator it = mShortName2Datum.begin(); it != mShortName2Datum.end(); ++it)
    {
      DB(1, "here");
    }

  std::for_each(mShortName2Datum.begin(), mShortName2Datum.end(), StaticDumpData);
  //for (std::map
  //  for_each(mShortName2Datum.begin(), mShortName2Datum.end(), &StaticDumpData);
}

void CommandLineData::DB(int iLevel, MyString text)
{
  if (iLevel >= iDebug)
    {
      cout << "CommandLineData:: " << text << endl;
    }
}


/** TwsCommonApp ****************************/
  
TwsCommonApp::TwsCommonApp(int iArgCount, const char** asArgs)
  :  iDebugAll(100), iDebugCommonApp(100), oCommandLineData(iArgCount, asArgs),
     sHost(""), iPort(7496)

{
  AddCommonCommandLineArgs();
}


int TwsCommonApp::RunMain()
{

  NYI("TwsCommonApp::RunMain (should be overridden in sub class)");

  return 0;
}

bool TwsCommonApp::ParseArgs()
{
  return oCommandLineData.ParseArgs();
}

void TwsCommonApp::AddCommonCommandLineArgs()
{
  oCommandLineData.AddIntArg("db", "debugAll", &iDebugAll);
  
  NFI("TwsCommonApp::AddCommonCommandLineArgs()");
}

bool TwsCommonApp::TryConnecting()
{
  pConn = new ClientConnection();
  int iWaitInSec = 3;
  struct timeval tTimeout = { iWaitInSec, 0};

  unsigned max_attempts = 10;
  if (! pConn->TryConnecting(max_attempts, sHost, iPort, iWaitInSec))
    {
       cerr << "Error: TwsWatcher: connection failed" << endl << flush;
    } else
    {
      return true;
    }
  
  return false;
}
