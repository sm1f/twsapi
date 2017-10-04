// CopyRight Stephen Morrisson 2017
// All rights reserved.




#ifndef __TWS_COMMON_APP__
#define __TWS_COMMON_APP__

#include <iostream>
#include <map>
#include <string>
#include <vector>

#define NYI(text) { cout << "NYI: " << text << endl; }
//#define NFI(text) { cout << "NFI: " << text << endl; }

#define NFI(text) {}

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

typedef std::map<MyString, CommandLineDatumPtr> Name2CLDatumMap;
 
class CommandLineData
{
 private:
  int iDebug;
  int iArgCount;
  const char** asArgs;
  std::vector<CommandLineDatumPtr> vArgData;
  Name2CLDatumMap mShortName2Datum;
  Name2CLDatumMap mFullName2Datum;
  
  
 public:
  CommandLineData(int iArgCount, const char** asArgs);

  virtual void AddIntArg(const char* shortName, const char* fullName, int* piVar);

  void DumpArgs(MyString title);
  void DumpData(MyString title);

  void DB(int iLevel, MyString text);
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
