

#ifndef __TWS_COMMON_APP__
#define __TWS_COMMON_APP__

#include <string>
#include <vector>




namespace TwsApp {

class CommandLineDatum
{
 private:
  int index;
 public:
  CommandLineDatum();
};
typedef CommandLineDatum* CommandLineDatumPtr;

class CommandLineData
{
 private:
  int iArgCount;
  const char** asArgs;
  std::vector<CommandLineDatumPtr> vArgData;
  
 public:
  CommandLineData(int iArgCount, const char** asArgs);

  void DumpArgs(const char* title);
};

  
class TwsCommonApp
{
 private:
  CommandLineData oCommandLineData;

  
 public:
  TwsCommonApp(int iArgCount, const char** asArgs);
  
  virtual int RunMain();
};

}


#endif //__TWS_COMMON_APP__
