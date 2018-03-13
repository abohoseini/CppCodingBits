
#ifndef UTILS_H
#define UTILS_H

#include <vector>

class Utils
{
public:
  template <typename T>
  static void PrintVector(std::vector<T> vect);

  template <typename T>
  static void Swap(T &a, T &b);
};

#endif // UTILS_H