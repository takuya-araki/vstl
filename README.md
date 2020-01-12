# Vectorized C++ Template Library

This is a C++ template library for vector architecture like SX-Aurora
TSUBASA. Most of the contents is taken from Frovedis; it is modified
to be used independently. 

It includes radix sort, prefix sum, set operations like intersection,
merge, etc. lower_bound, upper_bound, hashtable, and join.


# Installation

Modify the "TARGET" variable to x86 or ve according to the archtecture.
If you want to change the directory to install, please change
"INSTALLPATH" also. Then, 

    $ make

will compile the library.

If the installation is finished, please call

    # make install

to copy the library to the INSTALLPATH. Please do it as root (or use
sudo) if the INSTALLPATH cannot be accessed as normal user.


# How to use

There is sample programs in samples directory, which are also copied
to INSTALLPATH. Please refer them to understand how to use.

If the library is installed, the include file is in ${INSTALLPATH}/include
and library path is ${INSTALLPATH}/lib, which should be specified in the
compilation options -I and -L. You need to link libvstl_common and
libvstl_core_seq (omp version is under development).

To use each algorithm, you need to include corresponding header file.

## prefix_sum

    #include <vstl/seq/core/prefix_sum.hpp>

    template <class T>
    std::vector<T> prefix_sum(const std::vector<T>& val)
    
    template <class T>
    void prefix_sum(const T* valp, T* outp, size_t size)

This function computes prefix sum (inclusive scan). You can use both
pointer and std::vector. If you want exclusive scan, please use
pointer interface and shift the output pointer and size.

## radix_sort

    #include <vstl/seq/core/radix_sort.hpp>

    template <class K, class V>
    void radix_sort(std::vector<K>& key_array, std::vector<V>& val_array,
    	            bool positive_only = false)
    
    template <class K, class V>
    void radix_sort(K* key_array, V* val_array, size_t size,
                    bool positive_only = false)
    
    template <class K>
    void radix_sort(std::vector<K>& key_array, bool positive_only = false)
    
    template <class K>
    void radix_sort(K* key_array, size_t size, bool positive_only = false)

This function sort the input data (destructive). You can use both
pointer and std::vector. If value array is given, it is treated
key-value pair and sorted accordingly. If the last argument is true,
the function assumes that the keys are always positive, which reduces
some amount of computation. The type K need to be 32 bit or 64 bit
integer or float. 

If you want to sort the data in descending order, please use function
with "_desc" as follows: 
    
    template <class K, class V>
    void radix_sort_desc(std::vector<K>& key_array, std::vector<V>& val_array,
                         bool positive_only = false)
    
    template <class K, class V>
    void radix_sort_desc(K* key_array, V* val_array, size_t size,
                         bool positive_only = false)

    template <class K>
    void radix_sort_desc(std::vector<K>& key_array, bool positive_only = false)
    
    template <class K>
    void radix_sort_desc(K* key_array, size_t size, bool positive_only = false)

## set_intersection

    #include <vstl/seq/core/set_operations.hpp>

    template <class T>
    std::vector<T> set_intersection(const std::vector<T>& left,
                                    const std::vector<T>& right)
    
    std::vector<T> set_intersection(const T* leftp, size_t left_size,
                                    const T* rightp, size_t right_size)

It provides same functionality as std::set_intersection, though the
interface is different, and only PoD type is supported. The output is
std::vector because the output size is not know at the calling time.

## set_union

    #include <vstl/seq/core/set_operations.hpp>

    std::vector<T> set_union(const std::vector<T>& left,
                             const std::vector<T>& right)
    
    template <class T>
    std::vector<T> set_union(const T* leftp, size_t left_size,
                             const T* rightp, size_t right_size)

It provides same functionality as std::set_union. Only PoD type is
supported.

## set_difference

    #include <vstl/seq/core/set_operations.hpp>

    template <class T>
    std::vector<T> set_difference(const std::vector<T>& left,
                                  const std::vector<T>& right)
    
    template <class T>
    std::vector<T> set_difference(const T* leftp, size_t left_size,
                                  const T* rightp, size_t right_size) {

It provides same functionality as std::set_difference.Only PoD type is
supported.

## set_merge

    #include <vstl/seq/core/set_operations.hpp>

    template <class T>
    std::vector<T> set_merge(const std::vector<T>& left,
                             const std::vector<T>& right)

    template <class T>
    std::vector<T> set_merge(const T* leftp, size_t left_size,
                             const T* rightp, size_t right_size)

It provides same functionality as std::merge. Only PoD type is
supported. Following function supports key-value pair.

    template <class T, class K>
    void set_merge_pair(const std::vector<T>& left,
                        const std::vector<K>& left_val,
                        const std::vector<T>& right,
                        const std::vector<K>& right_val,
                        std::vector<T>& out,
                        std::vector<K>& out_val)
    
    template <class T, class K>
    void set_merge_pair(const T* leftp,
                        const K* left_valp,
                        size_t left_size,
                        const T* rightp,
                        const K* right_valp,
                        size_t right_size,
                        std::vector<T>& out,
                        std::vector<K>& out_val)

In this case, output key and value is stored in out and out_val.

If you want to use data sorted by descending order, use function with
"_desc". 

    template <class T>
    std::vector<T> set_merge_desc(const std::vector<T>& left,
                                  const std::vector<T>& right)
    
    template <class T>
    std::vector<T> set_merge_desc(const T* leftp, size_t left_size,
                                  const T* rightp, size_t right_size)
    
    template <class T, class K>
    void set_merge_pair_desc(const std::vector<T>& left,
                             const std::vector<K>& left_val,
                             const std::vector<T>& right,
                             const std::vector<K>& right_val,
                             std::vector<T>& out,
                             std::vector<K>& out_val)
    
    template <class T, class K>
    void set_merge_pair_desc(const T* leftp,
                             const K* left_valp,
                             size_t left_size,
                             const T* rightp,
                             const K* right_valp,
                             size_t right_size,
                             std::vector<T>& out,
                             std::vector<K>& out_val)

## set_separate

    #include <vstl/seq/core/set_operations.hpp>

    template <class T>
    std::vector<size_t> set_separate(const std::vector<T>& key)

    template <class T>
    std::vector<size_t> set_separate(const T* keyp, size_t size)

This function returns the index where the value of key changes. For
example, if key = {0,0,2,3,4,4,4,5}, the return value is
{0,2,3,4,7,8}. Please not that first data is always 0 and last data is
always the size of the key.

## set_unique

    #include <vstl/seq/core/set_operations.hpp>

    template <class T>
    std::vector<T> set_unique(const std::vector<T>& key)
    
    template <class T>
    std::vector<T> set_unique(const T* keyp, size_t size)

It returns unique data from the sorted key. For example, if key =
{0,0,2,3,4,4,4,5}, the return value is {0,2,3,4,5}.

## set_is_unique

    #include <vstl/seq/core/set_operations.hpp>

    template <class T>
    int set_is_unique(const std::vector<T>& key)

    template <class T>
    int set_is_unique(const T* keyp, size_t size)

It returns if the sorted key is unique.

## lower_bound

    #include <vstl/seq/core/lower_bound.hpp>

    template <class T>
    std::vector<size_t> lower_bound(const std::vector<T>& sorted,
                                    const std::vector<T>& to_find)

    template <class T>
    void lower_bound(const T* sorted, size_t sorted_size,
                     const T* to_find, size_t to_find_size,
                     size_t* ret)

This provides same functionality as std::lower_bound, except that the
searching data is also vector; vectorization is done by vectorizing
multiple search. It returns indexes of the result positions.

If the data is sorted by descending order, you can use functions with
"_desc". 

    template <class T>
    std::vector<size_t> lower_bound_desc(const std::vector<T>& sorted,
                                         const std::vector<T>& to_find)
    
    template <class T>
    void lower_bound_desc(const T* sorted, size_t sorted_size,
                          const T* to_find, size_t to_find_size,
                          size_t* ret)

## upper_bound

    #include <vstl/seq/core/upper_bound.hpp>

    template <class T>
    std::vector<size_t> upper_bound(const std::vector<T>& sorted,
                                    const std::vector<T>& to_find)
    
    template <class T>
    void upper_bound(const T* sorted, size_t sorted_size,
                     const T* to_find, size_t to_find_size,
                     size_t* ret)
    
    template <class T>
    std::vector<size_t> upper_bound_desc(const std::vector<T>& sorted,
                                         const std::vector<T>& to_find)

    template <class T>
    void upper_bound_desc(const T* sorted, size_t sorted_size,
                          const T* to_find, size_t to_find_size,
                          size_t* ret)

Same as lower_bound.

## reduce_by_key

    #include <vstl/seq/core/reduce_by_key.hpp>

    template <class K, class V>
    void reduce_by_key(const std::vector<K>& key, const std::vector<V>& val,
                       std::vector<K>& outkey, std::vector<V>& outval)
    
This add values of the same key; the unique key is stored in outkey,
and sum'ed value is stored in outval. For example, if the input key =
{0,1,1,2,2,3}, and val = {0,1,2,3,4,5}, the outkey = {0,1,2,3} and
the outval = {0,3,7,5}.

If you want to do other than addition, you can give your function as
the last argument of the function:

    template <class K, class V, class F>
    void reduce_by_key(const std::vector<K>& key, const std::vector<V>& val,
                       std::vector<K>& outkey, std::vector<V>& outval,
                       F func)

In this case, func should be function object so that it is possible to
inline-expand opeerator() of the func. You can use vstl::max and
vstl::min here.

If you want the number of the keys, you can use reduce_by_key_count.

    template <class K, class V>
    void reduce_by_key_count(const std::vector<K>& key, const std::vector<V>& val,
                             std::vector<K>& outkey, std::vector<V>& outval, 
                             std::vector<size_t>& outcount)
    
    template <class K, class V, class F>
    void reduce_by_key_count(const std::vector<K>& key, const std::vector<V>& val,
                             std::vector<K>& outkey, std::vector<V>& outval,
                             std::vector<size_t>& outcount, F func)

You can do the same thing by calling set_separate. Please check which
is faster.

## hash_table

    #include <vstl/seq/core/hashtable.hpp>

    template <class K, class V>
    class unique_hashtable;
    
    unique_hashtable::unique_hashtable(const std::vector<K>& k, 
                                       const std::vector<V>& v)
    
    std::vector<V> lookup(const std::vector<K>& k);
    std::vector<V> lookup(const std::vector<K>& k, std::vector<size_t>& miss);

It provides hash table of unique keys. The constructor takes
std::vector of key and value. Here, key should not contain duplicated
value. After creation of the hash table, you can lookup the value by
key using lookup. If you use `lookup(const std::vector<K>& k,
std::vector<size_t>& miss)`, you can get position where the key is not
in the hash table.
