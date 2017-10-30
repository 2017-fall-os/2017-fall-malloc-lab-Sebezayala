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
  p1 = bestFitAllocRegion(254000);
  p2 = bestFitAllocRegion(40000);
  p3 = bestFitAllocRegion(158000);
  p4 = bestFitAllocRegion(18000);
  p5 = bestFitAllocRegion(100000);
  p6 = bestFitAllocRegion(8000);
  p7 = bestFitAllocRegion(300000);
  p8 = bestFitAllocRegion(1000);
  p9 = bestFitAllocRegion(3000);
  p10 = bestFitAllocRegion(60000);
  freeRegion(p2);
  freeRegion(p3);
  freeRegion(p5);
  freeRegion(p7);
  freeRegion(p9);
  arenaCheck();
  p2 = bestFitAllocRegion(50000);
   arenaCheck();
  p3 = bestFitAllocRegion(70000);
   arenaCheck();
  p5 = bestFitAllocRegion(40000);
   arenaCheck();
  p7 = bestFitAllocRegion(105000);
   arenaCheck();
  p9 = bestFitAllocRegion(5000);
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
      if (bestFitAllocRegion(4) == 0) 
	break;
    getutime(&t2);
    printf("%d bestFitAllocRegion(4) required %f seconds\n", i, diffTimeval(&t2, &t1));
  }
  return 0;
}



