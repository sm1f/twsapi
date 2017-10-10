// CopyRight Stephen Morrisson 2017
// All rights reserved.



#include <stdio.h>
#include <iostream>

#include "TwsCommonApp.h"

using namespace TwsApp;


class TwsTest : public TwsCommonApp {
public:
  TwsTest(int iArgCount, const char** asArgs);
  virtual int RunMain();
};


TwsTest::TwsTest(int iArgCount, const char** asArgs)
  : TwsApp::TwsCommonApp(iArgCount, asArgs)
{}

int TwsTest::RunMain()
{
  return -1;
}

const unsigned MAX_ATTEMPTS = 1;
const unsigned SLEEP_TIME = 10;

using namespace std;

using namespace TwsApp;

int main(int argc, const char** argv)
{
  cout << "TwsTest V0.1" << endl;
  
  TwsTest that(argc, argv);

  int result = that.RunMain();

  if (result != 0)
    {
      cout << endl << "TwsTest returned: " << result << endl;
    }

  return result;
}
