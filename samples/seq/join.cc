#include <vstl/common/utility.hpp>
#include <vstl/seq/core/join.hpp>
#include "sample_util.hpp"

using namespace std;

int main(int argc, char* argv[]){
  vector<int> l1 = {0,2,4,5,6,8,10};
  vector<size_t> li1 = {0,1,2,3,4,5,6};
  vector<int> r1 = {1,2,3,4,5,6,7};
  vector<size_t> ri1 = {0,1,2,3,4,5,6};
  cout << "left: ";
  for(auto i: l1) cout << i << " ";
  cout << endl << "left index: ";
  for(auto i: li1) cout << i << " ";
  cout << endl << "right: ";
  for(auto i: r1) cout << i << " ";
  cout << endl << "right index: ";
  for(auto i: ri1) cout << i << " ";
  cout << endl;
  vector<size_t> lio1, rio1;
  vstl::seq::equi_join(l1, li1, r1, ri1, lio1, rio1);
  cout << "left index out: ";
  for(auto i: lio1) cout << i << " ";
  cout << endl << "right index out: ";
  for(auto i: rio1) cout << i << " ";
  cout << endl;

  auto left = gen_random<int>(argc, argv);
  auto right = gen_random2<int>(argc, argv);
  auto left_size = left.size();
  auto right_size = right.size();
  std::vector<size_t> left_index(left_size), right_index(right_size);
  auto left_indexp = left_index.data();
  auto right_indexp = right_index.data();
  for(size_t i = 0; i < left_size; i++) left_indexp[i] = i;
  for(size_t i = 0; i < right_size; i++) right_indexp[i] = i;
  std::vector<size_t> left_index_out, right_index_out;
  auto t1 = vstl::get_dtime();
  vstl::seq::equi_join(left, left_index, right, right_index,
                       left_index_out, right_index_out);
  auto t2 = vstl::get_dtime();
  cout << "time of " << left_size << " left and "
       << right_size << " right data: " << t2-t1 << " sec" << endl;
}
