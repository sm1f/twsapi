// CopyRight Stephen Morrisson 2017
// All rights reserved.


#ifndef __TWS_WATCHER_H__
#define  __TWS_WATCHER_H__

#include "TwsCommonApp.h"


namespace TwsApp {

class TwsWatcher : public TwsCommonApp
{
 protected:
  int iDebugWatcher;
  
 public:
  TwsWatcher(int iArgCount, const char** asArgs);

  virtual void DB(int level, MyString text);
  virtual int RunMain();

 protected:
  virtual void AddTwsWatcherArgs();

};


}



#endif // __TWS_WATCHER_H__
