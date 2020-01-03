#include "utility.hpp"
#include <sys/time.h>

namespace vstl {

double get_dtime() {
  struct timeval tv;
  gettimeofday(&tv, 0);
  return ((double)(tv.tv_sec) + (double)(tv.tv_usec) * 1.0e-6);
}

}
