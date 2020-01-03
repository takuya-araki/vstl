#include <vstl/common/utility.hpp>
#include <vstl/seq/core/set_operations.hpp>
#include "sample_util.hpp"

using namespace std;

int main(int argc, char* argv[]){
  vector<int> l1 = {10,8,6,4,2,0};
  vector<int> r1 = {5,4,3,2,1,0};
  cout << "left: ";
  for(auto i: l1) cout << i << " ";
  cout << endl << "right: ";
  for(auto i: r1) cout << i << " ";
  cout << endl;
  auto res = vstl::seq::set_merge_desc(l1,r1);
  cout << "merge_desc: " << endl;
  for(auto i: res) cout << i << " ";
  cout << endl;

  auto left = gen_left_desc<int>(argc, argv);
  auto right = gen_right_desc<int>(argc, argv);
  auto t1 = vstl::get_dtime();
  vstl::seq::set_merge_desc(left, right);
  auto t2 = vstl::get_dtime();
  auto size = left.size();
  cout << "time of " << size << " data: " << t2-t1 << " sec" << endl;;
}
