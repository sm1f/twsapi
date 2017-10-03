

#ifndef __TWS_WATCHER_H__
#define  __TWS_WATCHER_H__

#include "ClientConnection.h"
#include "TwsCommonApp.h"


namespace TwsApp {

class TwsWatcher : public TwsCommonApp
{
 protected:
  int iDebugWatcher;
  int iPort;
  MyString sHost;
 public:
  TwsWatcher(int iArgCount, const char** asArgs);

  virtual void DB(int level, MyString text);
  virtual int RunMain();

};


}



#endif // __TWS_WATCHER_H__
