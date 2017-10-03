

#ifndef __TWS_COMMON_APP__
#define __TWS_COMMON_APP__

#include <string>
#include <vector>
#include <map>

#define NYI(text) { cout << "NYI: " << text << endl; }
#define IGNORE(var) { if (false) cout << "" << var; }

namespace TwsApp {

typedef const char* MyString;

class CommandLineDatum
{
 private:
  MyString sShortName;
  MyString sFullName;
 public:
  CommandLineDatum(MyString sShort, MyString sFull);
};
typedef CommandLineDatum* CommandLineDatumPtr;

class CommandLineInt : public CommandLineDatum
{
 private:
  int* piVar;
 public:
  CommandLineInt(MyString sShort, MyString sFull, int* piVar);
};

class CommandLineData
{
 private:
  int iArgCount;
  const char** asArgs;
  std::vector<CommandLineDatumPtr> vArgData;
  std::map<MyString, CommandLineDatumPtr> mShortName2Datum;
  
  
 public:
  CommandLineData(int iArgCount, const char** asArgs);

  virtual void AddIntArg(const char* shortName, const char* fullName, int* piVar);

  void DumpArgs(MyString title);
  void DumpData(MyString title);
};


// int debug vars: higher more messages 0 should be none
 
class TwsCommonApp
{
 protected:
  int iDebugAll;
  int iDebugCommonApp;
 private:
  CommandLineData oCommandLineData;

  
 public:
  TwsCommonApp(int iArgCount, const char** asArgs);
  
  virtual int RunMain();
  virtual void AddCommonCommandLineArgs();
};

}


#endif //__TWS_COMMON_APP__
