#ifndef VSTL_UTILITY_HPP
#define VSTL_UTILITY_HPP

namespace vstl {

double get_dtime();

template <class T>
inline
T ceil_div(T a, T b){
  if(a == 0) return 0;
  else return (a - 1) / b + 1;
}

}

#endif
