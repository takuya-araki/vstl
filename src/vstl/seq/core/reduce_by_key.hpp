#ifndef REDUCE_BY_KEY_HPP
#define REDUCE_BY_KEY_HPP

#include <vector>
#include <functional>
#include <cstddef>

#if defined(_SX) || defined(__ve__)
#define REDUCE_BY_KEY_VLEN 256
#else
#define REDUCE_BY_KEY_VLEN 1
#endif

namespace vstl {
namespace seq {

#define REDUCE_BY_KEY_WITH_COUNT
#include "reduce_by_key.incl"
#undef REDUCE_BY_KEY_WITH_COUNT
#include "reduce_by_key.incl"

template <class K, class V, class F>
void reduce_by_key(const std::vector<K>& key, const std::vector<V>& val,
                   std::vector<K>& outkey, std::vector<V>& outval,
                   F func) {
  reduce_by_key(key.data(), val.data(), key.size(), outkey, outval, func);
}

template <class K, class V, class F>
void reduce_by_key_count(const std::vector<K>& key, const std::vector<V>& val,
                         std::vector<K>& outkey, std::vector<V>& outval,
                         std::vector<size_t>& outcount, F func) {
  reduce_by_key_count(key.data(), val.data(), key.size(), outkey, outval,
                      outcount, func);
}

template <class K, class V>
void reduce_by_key(const std::vector<K>& key, const std::vector<V>& val,
                   std::vector<K>& outkey, std::vector<V>& outval) { 
  reduce_by_key(key.data(), val.data(), key.size(), outkey, outval, 
                std::plus<V>());
}

template <class K, class V>
void reduce_by_key_count(const std::vector<K>& key, const std::vector<V>& val,
                         std::vector<K>& outkey, std::vector<V>& outval, 
                         std::vector<size_t>& outcount) {
  reduce_by_key_count(key.data(), val.data(), key.size(), outkey, outval,
                      outcount, std::plus<V>());
}

}
}
#endif
