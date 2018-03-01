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
  cb();

  callback::callback<decltype(l)> cb2{l, nullptr, nullptr};
  cb2();

  std::function<void()> prologueFun = []() -> void {
    LMSG("Prologue");
  };
  std::function<void()> cbFun = []() -> void {
    LMSG("Callback");
  };
  std::function<void()> epilogueFun = []() -> void {
    LMSG("Epilogue");
  };
  callback::callback<decltype(cbFun)> cbp(prologueFun, cbFun, epilogueFun);
  cbp();

  int m{100};
  std::function<int()> aFun = [m]() -> int {
    auto value{m * 10};
    LMSG(m << " * 10 = " << value);
    //std::cout << m << " * 10 = " << value << std::endl;
    return value;
  };
  callback::callback<decltype(aFun)> cb3{nullptr, aFun, nullptr};
  cb3();

  std::function<void()> nullFun{nullptr};
  callback::callback<decltype(nullFun)> cb4{nullptr, nullFun, nullptr};
  cb4();

  callback::callback<decltype(nullFun)> cb5{nullFun, nullFun, nullFun};
  cb5();
}

// main
int main()
{
  testCallback();

  return 0;
}

// eof

