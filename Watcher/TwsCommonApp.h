

#ifndef __TWS_COMMON_APP__
#define __TWS_COMMON_APP__

#include <string>

namespace TwsApp {

class TwsCommonApp
{
 private:
  int iArgCount;
  const char** asArgs;

  
 public:
  TwsCommonApp(int iArgCount, const char** asArgs);
  
  virtual int RunMain();

  virtual void DumpArgs(const char* title);

  
};

}


#endif //__TWS_COMMON_APP__
