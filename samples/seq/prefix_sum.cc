#include <vstl/common/utility.hpp>
#include <vstl/seq/core/prefix_sum.hpp>
#include "sample_util.hpp"

using namespace std;

int main(int argc, char* argv[]){
  vector<int> k1 = {3,1,5,2,4,0};
  cout << "src: ";
  for(auto i: k1) cout << i << " ";
  cout << endl;
  auto r1 = vstl::seq::prefix_sum(k1);
  cout << "after prefix_sum: " << endl;
  cout << "res: ";
  for(auto i: r1) cout << i << " ";
  cout << endl;

  auto key = gen_random<int>(argc, argv);
  auto t1 = vstl::get_dtime();
  auto r = vstl::seq::prefix_sum(key);
  auto t2 = vstl::get_dtime();
  auto size = key.size();
  cout << "time of " << size << " data: " << t2-t1 << " sec" << endl;;

  cout << endl;

  int mat[5][5] = {0,2,1,0,3,
                   1,0,1,2,1,
                   0,1,0,0,1,
                   2,2,1,1,0,
                   3,2,1,3,2};
  cout << "column-wise prefix sum (scan)" << endl << "src:" << endl;
  for(auto i=0; i<5; i++) {
    for(auto j=0; j<5; j++) cout << mat[i][j] << " ";
    cout << endl;
  }
  int out[5][5] = {0};
  for(auto j=0; j<5; j++) {
    vstl::seq::prefix_sum((const int*)&mat[0][j], 5, &out[0][j], 5, 5);
  }
  cout << "out:" << endl;
  for(auto i=0; i<5; i++) {
    for(auto j=0; j<5; j++) cout << out[i][j] << " ";
    cout << endl;
  }
}
