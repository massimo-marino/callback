//
// main.h
//
// Created by massimo on 1/27/18.
//
#pragma once

#include "callback.h"

#include <iostream>
#include <memory>
#include <type_traits>
////////////////////////////////////////////////////////////////////////////////

#define DEBUG_LOG
#ifdef DEBUG_LOG
// macros L and LL give the same result
#define L std::cout << "[" << __FILE__ << ":" << __LINE__ << ": " << __func__ << "]: ";
#define LL [](const std::string& function) {std::cout << "[" << __FILE__ << ":" << __LINE__ << ": " << function << "]: ";}(__func__);
// macros LMSG and LLMSG give the same result
#define LMSG(msg) std::cout << "[" << __FILE__ << ":" << __LINE__ << ": " << __func__ << "]: " << msg << std::endl;
#define LLMSG(msg) [](const std::string& function, const std::string& s) {std::cout << "[" << __FILE__ << ":" << __LINE__ << ": " << function << "]: "<< s  << std::endl;}(__func__, msg);
#else
#define L
#define LL
#define LMSG
#define LLMSG
#endif

// eof

