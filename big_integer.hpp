#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const uint64_t kBase = 10;

class BigInt {
 private:
  std::vector<int64_t> value_;
  bool negative_ = false;
  void Del();

 public:
  // constructors and destructor
  BigInt();
  BigInt(int64_t number);
  BigInt(std::string number);
  BigInt(const BigInt& number);
  ~BigInt();

  // equality operator
  BigInt& operator=(const BigInt& number);

  // arithmetic operator's overloading
  BigInt operator+(const BigInt& number) const;
  BigInt operator-(const BigInt& number) const;
  BigInt operator*(const BigInt& number) const;
  BigInt operator/(const BigInt& number) const;
  BigInt operator%(const BigInt& number) const;

  // assignment version of arithmetic operator's overloading
  BigInt& operator+=(const BigInt& number);
  BigInt& operator-=(const BigInt& number);
  BigInt& operator*=(const BigInt& number);
  BigInt& operator/=(const BigInt& number);
  BigInt& operator%=(const BigInt& number);

  // prefix increment & decrement operator's overloading
  BigInt& operator++();
  BigInt& operator--();

  // postfix increment & decrement operator's overloading
  BigInt operator++(int);
  BigInt operator--(int);

  // unary minus
  BigInt operator-() const;

  // logical operator's overloading
  bool operator==(const BigInt& number) const;
  bool operator!=(const BigInt& number) const;
  bool operator<=(const BigInt& number) const;
  bool operator>=(const BigInt& number) const;
  bool operator<(const BigInt& number) const;
  bool operator>(const BigInt& number) const;

  // input & output operator's overloading
  friend std::istream& operator>>(std::istream& in, BigInt& number);
  friend std::ostream& operator<<(std::ostream& os, const BigInt& number);
};
