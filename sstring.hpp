#pragma once
#include <string.h>

#include <iostream>
#include <vector>

size_t GetRealCap(size_t size);  // для подбора вместимости
class String {
 public:
  // конструкторы
  String();
  String(size_t size, char character);
  String(const char* str);

  // правило трёх
  String(const String& str);
  String& operator=(const String& str);
  ~String();

  // дефолтные методы
  void Clear();
  void PushBack(char character);
  void PopBack();

  // методы изменения размера
  void Resize(size_t new_size);
  void Resize(size_t new_size, char character);
  void Reserve(size_t new_cap);
  void ShrinkToFit();

  void Swap(String& other);  // свапнуть с другой строкой

  // методы для доступа данных о строке
  bool Empty() const;
  size_t Size() const;
  size_t Capacity() const;
  char* Data();
  const char* Data() const;

  // операторы сложения и умножения
  String& operator+=(const String& str);
  String operator+(const String& other) const;
  String operator*(size_t k_n) const;
  String& operator*=(size_t k_n);

  // булевые операторы
  /* некостантные */
  bool operator<(const String& str_2);
  bool operator<=(const String& str_2);
  bool operator>(const String& str_2);
  bool operator>=(const String& str_2);
  bool operator==(const String& str_2);
  bool operator!=(const String& str_2);

  /* константные */
  bool operator<(const String& str_2) const;
  bool operator<=(const String& str_2) const;
  bool operator>(const String& str_2) const;
  bool operator>=(const String& str_2) const;
  bool operator==(const String& str_2) const;
  bool operator!=(const String& str_2) const;

  // операторы и методы доступа
  /* неконстантные */
  char& operator[](size_t k_index);
  char& Front();
  char& Back();
  const char& Front() const;
  const char& Back() const;
  /* константные */
  char operator[](size_t k_index) const;

  // питоновские методы
  std::vector<String> Split(const String& delim = " ");
  String Join(const std::vector<String>& strings) const;

 private:
  char* string_;
  size_t size_;
  size_t capacity_;
  void Refill(size_t n_size) {
    String tmp = *this;
    delete[] string_;
    size_ = n_size;
    capacity_ = GetRealCap(size_);
    string_ = new char[capacity_ + 1];
    memcpy(string_, tmp.string_, tmp.size_);
  }
};

int Strcmp(const String& str_1, const String& str_2);

// операторы ввода и вывода
std::ostream& operator<<(std::ostream& os_out, const String& str);
std::istream& operator>>(std::istream& input, String& str);
