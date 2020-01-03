#include <vstl/common/utility.hpp>
#include <vstl/seq/core/set_operations.hpp>
#include "sample_util.hpp"

using namespace std;

int main(int argc, char* argv[]){
  vector<int> l1 = {0,2,4,6,8,10};
  vector<int> r1 = {0,1,2,3,4,5};
  cout << "left: ";
  for(auto i: l1) cout << i << " ";
  cout << endl << "right: ";
  for(auto i: r1) cout << i << " ";
  cout << endl;
  auto res = vstl::seq::set_union(l1,r1);
  cout << "union: " << endl;
  for(auto i: res) cout << i << " ";
  cout << endl;

  auto left = gen_left<int>(argc, argv);
  auto right = gen_right<int>(argc, argv);
  auto t1 = vstl::get_dtime();
  vstl::seq::set_union(left, right);
  auto t2 = vstl::get_dtime();
  auto size = left.size();
  cout << "time of " << size << " data: " << t2-t1 << " sec" << endl;;
}
