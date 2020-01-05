#include <vstl/common/utility.hpp>
#include <vstl/seq/core/set_operations.hpp>
#include "sample_util.hpp"

using namespace std;

int main(int argc, char* argv[]){
  vector<int> k1 = {0,0,2,3,4,4,4,5};
  cout << "key: ";
  for(auto i: k1) cout << i << " ";
  cout << endl;
  auto s1 = vstl::seq::set_separate(k1);
  cout << "separation point: ";
  for(auto i: s1) cout << i << " ";
  cout << endl;

  auto key = gen_random<int>(argc, argv);
  vstl::seq::radix_sort(key);
  auto t1 = vstl::get_dtime();
  auto sep = vstl::seq::set_separate(key);
  auto t2 = vstl::get_dtime();
  auto size = key.size();
  cout << "time of " << size << " data: " << t2-t1 << " sec" << endl;;
}
