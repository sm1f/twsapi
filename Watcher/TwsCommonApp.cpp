
#include <iostream>

#include "TwsCommonApp.h"

using namespace std;
using namespace TwsApp;


int TwsCommonApp::AppMain(int iArgCount, const char** asArgs)
{
  DumpArgs(NULL, iArgCount, asArgs);
  return 0;
}

void TwsCommonApp::DumpArgs(const char* sTitle, int iArgCount, const char** asArgs)
{
  if (sTitle != NULL) {
    cout << "" << sTitle << endl;
  }
  for (int i = 0; i < iArgCount; i++) {
    cout << "Arg [" << i << "]" << asArgs[i] << endl;
  }
}

