
#include <iostream>

#include "TwsCommonApp.h"

using namespace std;
using namespace TwsApp;

TwsCommonApp::TwsCommonApp(int iArgCountIn, const char** asArgsIn)
  : iArgCount(iArgCountIn), asArgs(asArgsIn)
{
}


int TwsCommonApp::RunMain()
{
  cout << "NYI RunMain" << endl;

  DumpArgs("Dumping Args:");
  
  return 0;
}

void TwsCommonApp::DumpArgs(const char* sTitle)
{
  if (sTitle != NULL) {
    cout << "" << sTitle << endl;
  }
  for (int i = 0; i < iArgCount; i++) {
        cout << "Arg [" << i << "]" << asArgs[i] << endl;
  }
}

