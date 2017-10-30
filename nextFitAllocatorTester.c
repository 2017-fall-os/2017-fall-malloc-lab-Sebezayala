#include "stdio.h"
#include "stdlib.h"
#include "myAllocator.h"
#include "sys/time.h"
#include <sys/resource.h>
#include <unistd.h>

double diffTimeval(struct timeval *t1, struct timeval *t2) {
  double d = (t1->tv_sec - t2->tv_sec) + (1.0e-6 * (t1->tv_usec - t2->tv_usec));
  return d;
}

void getutime(struct timeval *t)
{
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  *t = usage.ru_utime;
}

int main() 
{
  void *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10;
  arenaCheck();
  p1 = nextFitAllocRegion(254000);
  p2 = nextFitAllocRegion(40000);
  p3 = nextFitAllocRegion(158000);
  p4 = nextFitAllocRegion(18000);
  p5 = nextFitAllocRegion(100000);
  p6 = nextFitAllocRegion(8000);
  p7 = nextFitAllocRegion(300000);
  p8 = nextFitAllocRegion(1000);
  p9 = nextFitAllocRegion(3000);
  p10 = nextFitAllocRegion(60000);
  freeRegion(p2);
  freeRegion(p3);
  freeRegion(p5);
  freeRegion(p7);
  freeRegion(p9);
  arenaCheck();
  p2 = nextFitAllocRegion(50000);
   arenaCheck();
  p3 = nextFitAllocRegion(70000);
   arenaCheck();
  p5 = nextFitAllocRegion(40000);
   arenaCheck();
  p7 = nextFitAllocRegion(105000);
   arenaCheck();
  p9 = nextFitAllocRegion(5000);
  arenaCheck();
  freeRegion(p1);
  freeRegion(p4);
  freeRegion(p6);
  freeRegion(p8);
  freeRegion(p10);
  freeRegion(p2);
  freeRegion(p3);
  freeRegion(p5);
  freeRegion(p7);
  freeRegion(p9);
  arenaCheck();
  {				/* measure time for 10000 mallocs */
    struct timeval t1, t2;
    int i;
    getutime(&t1);
    for(i = 0; i < 10000; i++)
      if (nextFitAllocRegion(4) == 0) 
	break;
    getutime(&t2);
    printf("%d nextFitAllocRegion(4) required %f seconds\n", i, diffTimeval(&t2, &t1));
  }
  return 0;
}



