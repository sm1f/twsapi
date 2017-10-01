
#include <iostream>

#include "TwsWatcher.h"

using namespace std;
using namespace TwsApp;

TwsWatcher::TwsWatcher(int iArgCount, const char** asArgs)
  : TwsCommonApp(iArgCount, asArgs)
{
  /*  
  
  for (int i = 0; i < iArgCount; i++) {
    cout << "Arg [" << i << "]" << asArgs[i] << endl;
  }
  */
}

