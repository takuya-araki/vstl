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
}
