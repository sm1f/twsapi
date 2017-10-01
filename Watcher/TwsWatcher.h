

#ifndef __TWS_WATCHER_H__
#define  __TWS_WATCHER_H__

#include "TwsCommonApp.h"

namespace TwsApp {

class TwsWatcher : public TwsCommonApp
{

 public:
  static int StaticMain(int iArgCount, const char** asArgs);


  virtual int AppMain(int iArgCount, const char** asArgs);
};


}



#endif // __TWS_WATCHER_H__
