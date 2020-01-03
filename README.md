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