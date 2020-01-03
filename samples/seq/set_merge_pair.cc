#include <vstl/common/utility.hpp>
#include <vstl/seq/core/set_operations.hpp>
#include "sample_util.hpp"

using namespace std;

int main(int argc, char* argv[]){
  vector<int> l1 = {0,2,4,6,8,10};
  vector<int> lv1 = {10,20,30,40,50,60};
  vector<int> r1 = {0,1,2,3,4,5};
  vector<int> rv1 = {100,200,300,400,500,600};
  cout << "left: ";
  for(auto i: l1) cout << i << " ";
  cout << endl << "left value: ";
  for(auto i: lv1) cout << i << " ";
  cout << endl << "right: ";
  for(auto i: r1) cout << i << " ";
  cout << endl << "right value: ";
  for(auto i: rv1) cout << i << " ";
  cout << endl;
  std::vector<int> o1, ov1;
  vstl::seq::set_merge_pair(l1,lv1,r1,rv1,o1,ov1);
  cout << "merge_pair: " << endl;
  cout << "out: ";
  for(auto i: o1) cout << i << " ";
  cout << endl;
  cout << "out value: ";
  for(auto i: ov1) cout << i << " ";
  cout << endl;

  auto left = gen_left<int>(argc, argv);
  auto right = gen_right<int>(argc, argv);
  auto size = left.size();
  std::vector<int> left_val(size), right_val(size);
  auto left_valp = left_val.data();
  auto right_valp = right_val.data();
  for(size_t i = 0; i < size; i++) {
    left_valp[i] = i * 10;
    right_valp[i] = i * 100;
  }
  auto t1 = vstl::get_dtime();
  std::vector<int> out, out_val;
  vstl::seq::set_merge_pair(left, left_val, right, right_val, out, out_val);
  auto t2 = vstl::get_dtime();
  cout << "time of " << size << " data: " << t2-t1 << " sec" << endl;;
}
