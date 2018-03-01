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

  explicit callback() noexcept(false)
  {
    prologueFun_();
  }

  explicit callback(CBFUN prologueFun,
                    CBFUN callbackFun,
                    CBFUN epilogueFun) noexcept(false) :
          prologueFun_(prologueFun),
          callbackFun_(callbackFun),
          epilogueFun_(epilogueFun)
  {
    if ( prologueFun_ )
    {
      prologueFun_();
    }
    // add an else block if needed
    // else { ... }
  }

  ~callback() noexcept(false)
  {
    if ( epilogueFun_ )
    {
      epilogueFun_();
    }
    // add an else block if needed
    // else { ... }
  }

  void
  operator ()() noexcept(false)
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

  CBFUN prologueFun_ {defaultCallbackFun_};
  CBFUN callbackFun_ {defaultCallbackFun_};
  CBFUN epilogueFun_ {defaultCallbackFun_};
};  // class callback

template <typename CBFUN>
CBFUN callback<CBFUN>::defaultCallbackFun_ = []() noexcept(true) -> void {};

}  // namespace callback
