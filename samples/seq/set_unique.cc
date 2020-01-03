#include <vstl/common/utility.hpp>
#include <vstl/seq/core/set_operations.hpp>
#include "sample_util.hpp"

using namespace std;

int main(int argc, char* argv[]){
  vector<int> k1 = {0,0,2,3,4,4,4,5};
  cout << "key: ";
  for(auto i: k1) cout << i << " ";
  cout << endl;
  cout << "is_unique: " << vstl::seq::set_is_unique(k1) << endl;
  auto u1 = vstl::seq::set_unique(k1);
  cout << "set_unique: ";
  for(auto i: u1) cout << i << " ";
  cout << endl;

  auto key = gen_random<double>(argc, argv);
  vstl::seq::radix_sort(key);
  auto t1 = vstl::get_dtime();
  auto sep = vstl::seq::set_unique(key);
  auto t2 = vstl::get_dtime();
  auto size = key.size();
  cout << "time of " << size << " data: " << t2-t1 << " sec" << endl;;
}
