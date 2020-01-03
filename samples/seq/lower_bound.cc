#include <vstl/common/utility.hpp>
#include <vstl/seq/core/lower_bound.hpp>
#include "sample_util.hpp"

using namespace std;

int main(int argc, char* argv[]){
  vector<int> s1 = {0,2,4,5,6,8,10};
  vector<int> f1 = {8,3,5};
  cout << "sorted: ";
  for(auto i: s1) cout << i << " ";
  cout << endl << "to_find: ";
  for(auto i: f1) cout << i << " ";
  cout << endl;
  auto res = vstl::seq::lower_bound(s1,f1);
  cout << "lower_bound: " << endl;
  for(auto i: res) cout << i << " ";
  cout << endl;

  auto sorted = gen_sorted<int>(argc, argv);
  auto to_find = gen_random2<int>(argc, argv);
  auto t1 = vstl::get_dtime();
  vstl::seq::lower_bound(sorted, to_find);
  auto t2 = vstl::get_dtime();
  auto sorted_size = sorted.size();
  auto to_find_size = to_find.size();
  cout << "time of " << sorted_size << " sorted data and "
       << to_find_size << " to find data: " << t2-t1 << " sec" << endl;;
}
