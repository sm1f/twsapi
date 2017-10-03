
#include <iostream>

#include "TwsCommonApp.h"

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

void CommandLineData::AddIntArg(const char* sShortName, const char* sFullName, int* piInt)
{
  vArgData.push_back(new CommandLineInt(sShortName, sFullName, piInt));
  NYI("CommandLineData::AddIntArg(const char* name, Int* pInt)");
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

void StaticDumpData(std::pair<MyString, CommandLineDatumPtr>& pair)
{
    NYI("StaticDumpData(std::pair<MyString, CommandLineDatumPtr>& pair): ");
}

void CommandLineData::DumpData(MyString sTitle)
{
  if (sTitle != NULL)
    {
      cout << "" << sTitle << endl;
    }
  //  std::for_each(mShortName2Datum.begin(), mShortName2Datum.end(), StaticDumpData);
}
/** TwsCommonApp ****************************/
  
TwsCommonApp::TwsCommonApp(int iArgCount, const char** asArgs)
  :  iDebugAll(100), iDebugCommonApp(100), oCommandLineData(iArgCount, asArgs)
{
}


int TwsCommonApp::RunMain()
{

  AddCommonCommandLineArgs();
  
  cout << "NYI RunMain" << endl;

  return 0;
}

void TwsCommonApp::AddCommonCommandLineArgs()
{
  oCommandLineData.AddIntArg("db", "debugAll", &iDebugAll);
  
  NYI("TwsCommonApp::AddCommonCommandLineArgs()");
}

