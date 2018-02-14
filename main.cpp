//
// main.cpp
//
#include "main.h"
////////////////////////////////////////////////////////////////////////////////

static void testCallback ()
{
  std::function<void()> l = []() -> void {
    LMSG("Ciao Ciao");
  };
  callback::callback<std::function<void()>> cb{};
  callback::callback<decltype(l)> cb2{l};

  std::function<void()> prologueFun = []() -> void {
    LMSG("Prologue");
  };
  std::function<void()> cbFun = []() -> void {
    LMSG("Callback");
  };
  callback::callbackWithPrologue<decltype(cbFun)> cbp(prologueFun, cbFun);

  int m{100};
  std::function<int()> aFun = [m]() -> int {
    auto value{m * 10};
    std::cout << m << " * 10 = " << value << std::endl;
    return value;
  };
  callback::callback<decltype(aFun)> cb3{aFun};

  std::function<void()> nullFun{nullptr};
  callback::callback<decltype(nullFun)> cb4{nullFun};
  callback::callbackWithPrologue<decltype(nullFun)> cb5{nullFun, nullFun};
}

// main
int main()
{
  testCallback();

  return 0;
}

// eof

