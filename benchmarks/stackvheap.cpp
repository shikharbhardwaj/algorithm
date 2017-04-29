#define NONIUS_RUNNER
#include "nonius.h++"
NONIUS_BENCHMARK("1000 on the stack",[](nonius::chronometer meter){
        meter.measure([]{
            {
                int ar[10000];
            }
            });
    })
NONIUS_BENCHMARK("1000 on the heap",[](nonius::chronometer meter){
        meter.measure([]{
            {
                int* ar = new int[10000];
                delete[] ar;
            }
            });
})
