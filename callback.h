//
// callback.h
//
// Created by massimo on 2/5/18.
//
#pragma once

#include<functional>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace callback {

// default callback function signature
using cbfun_t = std::function<void()>;

template <typename CBFUN = cbfun_t>
class callback final {

public:

  callback() = default;

  explicit callback(CBFUN cbFun) noexcept(true) :
          callbackFun_(cbFun)
  {}

  ~callback() noexcept(false)
  {
    if ( callbackFun_ )
    {
      callbackFun_();
    }
    // add an else block if needed
    // else { ... }
  }

  // forbid all these operations
  callback(const callback &rhs) = delete;
  callback &operator=(const callback &rhs) = delete;
  callback(callback &&rhs) = delete;
  callback &operator=(callback &&rhs) = delete;
  void *operator new(std::size_t) = delete;

private:

  static CBFUN defaultCallbackFun_;

  CBFUN callbackFun_ {defaultCallbackFun_};
};  // class callback

template <typename CBFUN>
CBFUN callback<CBFUN>::defaultCallbackFun_{[]() -> void {}};

////////////////////////////////////////////////////////////////////////////////

template <typename CBFUN = cbfun_t>
class callbackWithPrologue final {

public:

  explicit callbackWithPrologue() noexcept(false)
  {
    prologueFun_();
  }

  explicit callbackWithPrologue(CBFUN prologueFun, CBFUN cbFun) noexcept(false) :
          prologueFun_(prologueFun),
          callbackFun_(cbFun)
  {
    if ( prologueFun_ )
    {
      prologueFun_();
    }
    // add an else block if needed
    // else { ... }
  }

  ~callbackWithPrologue() noexcept(false)
  {
    if ( callbackFun_ )
    {
      callbackFun_();
    }
    // add an else block if needed
    // else { ... }
  }

  // forbid all these operations
  callbackWithPrologue(const callbackWithPrologue &rhs) = delete;
  callbackWithPrologue &operator=(const callbackWithPrologue &rhs) = delete;
  callbackWithPrologue(callbackWithPrologue &&rhs) = delete;
  callbackWithPrologue &operator=(callbackWithPrologue &&rhs) = delete;
  void *operator new(std::size_t) = delete;

private:

  static CBFUN defaultCallbackFun_;

  CBFUN prologueFun_ {defaultCallbackFun_};
  CBFUN callbackFun_ {defaultCallbackFun_};
};  // class callbackWithPrologue

template <typename CBFUN>
CBFUN callbackWithPrologue<CBFUN>::defaultCallbackFun_{[]() -> void {}};

}  // namespace callback
