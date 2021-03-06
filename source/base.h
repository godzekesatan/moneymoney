#ifndef MONEYMONEY_BASE_H_
#define MONEYMONEY_BASE_H_

/**
 * Allows us to save some typing when defining a purely abstract base class.
 */
#define DECLARE_INTERFACE(interface)\
public:\
  virtual ~interface() = default;\
  interface(const interface &) = delete;\
  interface &operator =(const interface &) = delete;\
protected:\
  interface() = default;\
private:

#endif  // MONEYMONEY_BASE_H_
