#ifndef MONEYMONEY_BASE_H_
#define MONEYMONEY_BASE_H_

#define DECLARE_INTERFACE(interface)\
public:\
  virtual ~interface() {}\
protected:\
  interface() {}\
private:

#endif  // MONEYMONEY_BASE_H_
