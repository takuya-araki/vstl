#include <vstl/common/utility.hpp>
#include <vstl/seq/core/hashtable.hpp>
#include "sample_util.hpp"

using namespace std;

int main(int argc, char* argv[]){
  vector<int> k1 = {0,2,4,5,6,8,10};
  vector<int> v1 = {0,1,2,3,4,5,6};
  vector<int> f1 = {8,3,5};
  cout << "key: ";
  for(auto i: k1) cout << i << " ";
  cout << endl << "value: ";
  for(auto i: v1) cout << i << " ";
  cout << endl << "to_find: ";
  for(auto i: f1) cout << i << " ";
  cout << endl;
  vstl::seq::unique_hashtable<int,int> h1(k1,v1);
  std::vector<size_t> m1;
  auto r1 = h1.lookup(f1,m1);
  cout << "found value: " << endl;
  for(auto i: r1) cout << i << " ";
  cout << endl;
  cout << "missed: " << endl;
  for(auto i: m1) cout << i << " ";
  cout << endl;

  auto key = gen_unique<int>(argc, argv);
  auto key_size = key.size();
  std::vector<int> value(key_size);
  auto valuep = value.data();
  for(size_t i = 0; i < key_size; i++) valuep[i] = i;
  auto to_find = gen_random2<int>(argc, argv);
  std::vector<size_t> missed;
  auto t1 = vstl::get_dtime();
  vstl::seq::unique_hashtable<int,int> hashtable(key,value);
  auto t2 = vstl::get_dtime();
  auto found = hashtable.lookup(to_find, missed);
  auto t3 = vstl::get_dtime();
  auto to_find_size = to_find.size();
  cout << "time of " << key_size << " key data and "
       << to_find_size << " to find data: " << endl;
  cout << "creation time: " << t2-t1 << " sec" << endl;
  cout << "find time: " << t3-t2 << " sec" << endl;
}
