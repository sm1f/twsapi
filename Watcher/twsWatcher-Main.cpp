// CopyRight Stephen Morrisson 2017
// All rights reserved.



#include <stdio.h>
#include <iostream>

#include "TwsWatcher.h"

const unsigned MAX_ATTEMPTS = 1;
const unsigned SLEEP_TIME = 10;

using namespace std;

using namespace TwsApp;

int main(int argc, const char** argv)
{
  cout << "TwsWatcher V0.2" << endl;
  
  TwsWatcher that(argc, argv);
  //  that.SetGeneralDebugLevel(100);

  int result = that.RunMain();

  if (result != 0)
    {
      cout << endl << "TwsWatcher returned: " << result << endl;
    }

  return result;
}
