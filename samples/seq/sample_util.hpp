#include <stdlib.h>
#include <vector>
#include <limits>
#include <iostream>
#include <vstl/seq/core/radix_sort.hpp>
#include <vstl/seq/core/set_operations.hpp>

template <class T>
std::vector<T> gen_random(size_t size) {
  std::vector<T> ret(size);
  for(size_t i = 0; i < size; i++) {
//    ret[i] = std::numeric_limits<T>::max() * drand48();
    ret[i] = size * drand48();
  }
  return ret;
}

template <class T>
std::vector<T> gen_random(int argc, char* argv[]) {
  int pow = 20;
  if(argc < 2) {
    std::cerr << "data size is set to 2^20; you can specify it as arg[1]"
              << std::endl;
  } else {
    pow = atoi(argv[1]);
  }
  size_t size = size_t(1) << pow;
  return gen_random<T>(size-1025);
}

template <class T>
std::vector<T> gen_left(size_t size) {
  std::vector<T> ret(size);
  auto retp = ret.data();
  for(size_t i = 0; i < size; i++) {
    retp[i] = size * 2 * drand48();
  }
  vstl::seq::radix_sort(ret);
  return ret;
}

template <class T>
std::vector<T> gen_right(size_t size) {
  std::vector<T> ret(size);
  auto retp = ret.data();
  for(size_t i = 0; i < size; i++) {
    retp[i] = size * 3 * drand48();
  }
  vstl::seq::radix_sort(ret);
  return ret;
}

template <class T>
std::vector<T> gen_left(int argc, char* argv[]) {
  int pow = 20;
  if(argc < 2) {
    std::cerr << "data size is set to 2^20; you can specify it as arg[1]"
              << std::endl;
  } else {
    pow = atoi(argv[1]);
  }
  size_t size = size_t(1) << pow;
  return gen_left<T>(size-1025);
}

template <class T>
std::vector<T> gen_right(int argc, char* argv[]) {
  int pow = 20;
  if(argc < 2) {
    std::cerr << "data size is set to 2^20; you can specify it as arg[1]"
              << std::endl;
  } else {
    pow = atoi(argv[1]);
  }
  size_t size = size_t(1) << pow;
  return gen_left<T>(size-1025);
}

template <class T>
std::vector<T> gen_left_desc(size_t size) {
  std::vector<T> ret(size);
  auto retp = ret.data();
  for(size_t i = 0; i < size; i++) {
    retp[i] = size * 2 * drand48();
  }
  vstl::seq::radix_sort_desc(ret);
  return ret;
}

template <class T>
std::vector<T> gen_right_desc(size_t size) {
  std::vector<T> ret(size);
  auto retp = ret.data();
  for(size_t i = 0; i < size; i++) {
    retp[i] = size * 3 * drand48();
  }
  vstl::seq::radix_sort_desc(ret);
  return ret;
}

template <class T>
std::vector<T> gen_left_desc(int argc, char* argv[]) {
  int pow = 20;
  if(argc < 2) {
    std::cerr << "data size is set to 2^20; you can specify it as arg[1]"
              << std::endl;
  } else {
    pow = atoi(argv[1]);
  }
  size_t size = size_t(1) << pow;
  return gen_left_desc<T>(size-1025);
}

template <class T>
std::vector<T> gen_right_desc(int argc, char* argv[]) {
  int pow = 20;
  if(argc < 2) {
    std::cerr << "data size is set to 2^20; you can specify it as arg[1]"
              << std::endl;
  } else {
    pow = atoi(argv[1]);
  }
  size_t size = size_t(1) << pow;
  return gen_left_desc<T>(size-1025);
}

template <class T>
std::vector<T> gen_sorted(size_t size) {
  std::vector<T> ret(size);
  for(size_t i = 0; i < size; i++) {
//    ret[i] = std::numeric_limits<T>::max() * drand48();
    ret[i] = size * drand48();
  }
  vstl::seq::radix_sort(ret);
  return ret;
}

template <class T>
std::vector<T> gen_sorted(int argc, char* argv[]) {
  int pow = 20;
  if(argc < 2) {
    std::cerr << "data size is set to 2^20; you can specify it as arg[1]"
              << std::endl;
  } else {
    pow = atoi(argv[1]);
  }
  size_t size = size_t(1) << pow;
  return gen_sorted<T>(size-1025);
}

template <class T>
std::vector<T> gen_random2(int argc, char* argv[]) {
  int pow = 20;
  if(argc < 3) {
    std::cerr << "data size is set to 2^20; you can specify it as arg[2]"
              << std::endl;
  } else {
    pow = atoi(argv[2]);
  }
  size_t size = size_t(1) << pow;
  return gen_random<T>(size-1025);
}

template <class T>
std::vector<T> gen_unique(size_t size) {
  std::vector<T> ret(size);
  for(size_t i = 0; i < size; i++) {
//    ret[i] = std::numeric_limits<T>::max() * drand48();
    ret[i] = size * drand48();
  }
  vstl::seq::radix_sort(ret);
  return vstl::seq::set_unique(ret);
}

template <class T>
std::vector<T> gen_unique(int argc, char* argv[]) {
  int pow = 20;
  if(argc < 2) {
    std::cerr << "original data size is set to 2^20; you can specify it as arg[1]"
              << std::endl;
  } else {
    pow = atoi(argv[1]);
  }
  size_t size = size_t(1) << pow;
  return gen_unique<T>(size-1025);
}
