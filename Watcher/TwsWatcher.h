// CopyRight Stephen Morrisson 2017
// All rights reserved.


#ifndef __TWS_WATCHER_H__
#define  __TWS_WATCHER_H__

#include "ClientConnection.h"
#include "TwsCommonApp.h"


namespace TwsApp {

class TwsWatcher : public TwsCommonApp
{
 protected:
  int iDebugWatcher;
  MyString sHost;
  int iPort;
  
 public:
  TwsWatcher(int iArgCount, const char** asArgs);

  virtual void DB(int level, MyString text);
  virtual int RunMain();

};


}



#endif // __TWS_WATCHER_H__
