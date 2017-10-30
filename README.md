# os-malloc

## Modifications

- Added implementations for both next-fit and best-fit policies
- Modified resizeRegion method to enlarge the current region if the next region is unallocated and has enough space

Added 3 new files to test each policy: 
- bestFitAllocatorTester
- firstFitAllocatorTester
- nextFitAllocatorTester

Each tester allocate 10 blocks of memory each different size(i.e p1=254000 p2=40000,etc), they free 5 blocks and then allocate 5 blocks again each of different size. All testers use the same sizes when allocating so that we can see the diffenrces(i.e p1 for bestFitAllocatorTester is the same size as p1 of firstFitAllocator).

All these testers use direct testing only, that is they do not use malloc.c, however they were tested using malloc.c and they do work.

Testing for the resizeRegion are implemented in both myAllocatorTest1 and test1.

To compile and clean follow original readme instructions.


## Original README
This directory contains:

myAllocator.c: a first-fit allocator
myAllocator.h: its header file

myAllocatorTest1.c: a test program for my allocator 

malloc.c: a replacement for malloc that uses my allocator
test1.c: a test program that uses this replacement malloc

There are two different testers as some implementations of printf
call malloc to allocate buffer space. This causes test1 to behave
improperly as it uses myAllocator as a malloc replacement. In this
case myAllocatorTest1 will function correctly. The only difference
between the programs is that test1 uses myAllocator as a malloc
replacement and myAllocatorTest1 uses myAllocator directly.

Makefile: a fairly portable "makefile", targets "all" and "clean"

To compile: 
 $ make 
To clean:
 $ make clean

The cygwin runtime uses malloc() and brk() extensively.  It is
interesting to compare the output of test1 & myAllocatorTest1.  All
those extra allocated regions are being used by cygwin's libraries!

