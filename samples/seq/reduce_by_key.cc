#include <vstl/common/utility.hpp>
#include <vstl/seq/core/reduce_by_key.hpp>
#include "sample_util.hpp"

using namespace std;

int main(int argc, char* argv[]){
  vector<int> k1 = {0,1,1,2,2,3};
  vector<int> v1 = {0,1,2,3,4,5};
  cout << "key: ";
  for(auto i: k1) cout << i << " ";
  cout << endl << "val: ";
  for(auto i: v1) cout << i << " ";
  cout << endl;
  std::vector<int> o1, ov1;
  vstl::seq::reduce_by_key(k1, v1, o1, ov1);
  cout << "out key: ";
  for(auto i: o1) cout << i << " ";
  cout << endl << "out val: ";
  for(auto i: ov1) cout << i << " ";
  cout << endl;

  auto key = gen_random<int>(argc, argv);
  vstl::seq::radix_sort(key);
  auto size = key.size();
  std::vector<int> val(size);
  auto valp = val.data();
  for(size_t i = 0; i < size; i++) valp[i] = i;
  std::vector<int> out, outval;
  auto t1 = vstl::get_dtime();
  vstl::seq::reduce_by_key(key, val, out, outval);
  auto t2 = vstl::get_dtime();
  cout << "time of " << size << " data: " << t2-t1 << " sec" << endl;;
}
