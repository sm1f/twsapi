
#include <iostream>

#include "TwsCommonApp.h"

using namespace std;
using namespace TwsApp;

/** CommandLineDatum *************************/
CommandLineDatum::CommandLineDatum()
{
}


/** CommandLineData *************************/

CommandLineData::CommandLineData(int iArgCountIn, const char** asArgsIn)
  : iArgCount(iArgCountIn), asArgs(asArgsIn)
{
}

void CommandLineData::DumpArgs(const char* sTitle)
{
  if (sTitle != NULL) {
    cout << "" << sTitle << endl;
  }
  for (int i = 0; i < iArgCount; i++) {
        cout << "Arg [" << i << "]" << asArgs[i] << endl;
  }
}



/** TwsCommonApp ****************************/
  
TwsCommonApp::TwsCommonApp(int iArgCount, const char** asArgs)
  : oCommandLineData(iArgCount, asArgs)
{
}


int TwsCommonApp::RunMain()
{
  
  cout << "NYI RunMain" << endl;

  //  DumpArgs("Dumping Args:");
  
  return 0;
}

