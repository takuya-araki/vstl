#include <vstl/common/utility.hpp>
#include <vstl/seq/core/radix_sort.hpp>
#include "sample_util.hpp"

using namespace std;

int main(int argc, char* argv[]){
  vector<int> k1 = {3,1,5,2,4,0};
  vector<int> v1 = {0,1,2,3,4,5};
  cout << "key: ";
  for(auto i: k1) cout << i << " ";
  cout << endl << "val: ";
  for(auto i: v1) cout << i << " ";
  cout << endl;
  vstl::seq::radix_sort(k1, v1);
  cout << "after sort: " << endl;
  cout << "key: ";
  for(auto i: k1) cout << i << " ";
  cout << endl << "val: ";
  for(auto i: v1) cout << i << " ";
  cout << endl;

  auto key = gen_random<double>(argc, argv);
  auto size = key.size();
  std::vector<int> val(size);
  auto valp = val.data();
  for(size_t i = 0; i < size; i++) valp[i] = i;
  auto t1 = vstl::get_dtime();
  vstl::seq::radix_sort(key, val);
  auto t2 = vstl::get_dtime();
  cout << "time of " << size << " data: " << t2-t1 << " sec" << endl;;
}
