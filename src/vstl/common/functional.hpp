#ifndef VSTL_FUNCTIONAL_HPP
#define VSTL_FUNCTIONAL_HPP

namespace vstl {

template <class T>
struct plus {
  T operator()(T a, T b){return a + b;}
};

template <class T>
struct max {
  T operator()(T a, T b){return a < b ? b : a;}
};

template <class T>
struct min {
  T operator()(T a, T b){return a < b ? a : b;}
};

}
#endif
