
#include <iostream>

#include "TwsWatcher.h"

using namespace std;
using namespace TwsApp;

int TwsWatcher::AppMain(int iArgCount, const char** asArgs)
{
  for (int i = 0; i < iArgCount; i++) {
    cout << "Arg [" << i << "]" << asArgs[i] << endl;
  }
  return 0;
}

