CFLAGS	= -g
CC	= gcc
OBJ	= firstFitAllocatorTester nextFitAllocatorTester bestFitAllocatorTester myAllocatorTest1 test1

all: $(OBJ)

firstFitAllocatorTester: myAllocator.o firstFitAllocatorTester.o
	$(CC) $(CFLAGS) -o $@ $^

nextFitAllocatorTester: myAllocator.o nextFitAllocatorTester.o
	$(CC) $(CFLAGS) -o $@ $^
	
bestFitAllocatorTester: myAllocator.o bestFitAllocatorTester.o
	$(CC) $(CFLAGS) -o $@ $^
	
myAllocatorTest1: myAllocator.o myAllocatorTest1.o
	$(CC) $(CFLAGS) -o $@ $^

test1: myAllocator.o malloc.o test1.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -f *.o $(OBJ) 

