

#ifndef __TWS_COMMON_APP__
#define __TWS_COMMON_APP__

#include <string>

namespace TwsApp {

class TwsCommonApp
{
  
 public:
  virtual int AppMain(int iArgCount, const char** asArgs);

  virtual void DumpArgs(const char* title, int iArgCount, const char** asArgs);

  
};

}


#endif //__TWS_COMMON_APP__
