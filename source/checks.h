#ifndef MONEYMONEY_CHECKS_H_
#define MONEYMONEY_CHECKS_H_

#include <cstdlib>
#include <iostream>
#include <string>

#define CHECK_STATE(state) \
  CheckState(#state, state, __LINE__, __FILE__);

#define FAIL(message) \
  Fail(message, __LINE__, __FILE__);

inline void Fail(const std::string &message, int line, const std::string &file);

inline void CheckState(const std::string &message,
                       bool state,
                       int line,
                       const std::string &file) {
  if (!state) {
    Fail(message + " violated", line, file);
    exit(1);
  }
}

inline void Fail(const std::string &message, int line, const std::string &file) {
  std::cerr << "ERROR: " << message << " on line " << line << " of " << file << std::endl;
  exit(1);
}

#endif  // MONEYMONEY_CHECKS_H_
