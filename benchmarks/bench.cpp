#define NONIUS_RUNNER
#include "nonius.h++"
#include <algorithm>
#include <limits>
#include <random>
using std::sort;
const int test_size = 500000;
int *ar;
std::vector<int> vint;
std::random_device rd;
std::mt19937 mt(rd());
std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
namespace quick{
    inline void swap(int *a, int *b){
        int t = *a;
        *a = *b;
        *b = t;
    }
    void insertion_sort(int ar[], int lo, int hi){
        for(int i = lo+1;i<=hi;i++){
            int cur = ar[i];
            int j = i-1;
            while(ar[j] > cur && j >= lo){
                ar[j+1] = ar[j];
                j--;
            }
            ar[j+1] = cur;
        }
    }
    int partition(int ar[], int lo, int hi){
        int i = lo;
        int j = hi+1;
        while(true){
            while(ar[++i] < ar[lo]){
                if(i > hi)
                    break;
            }
            while(ar[lo] < ar[--j]);
            if(i >= j)
                break;
            swap(&ar[i], &ar[j]);
        }
        swap(&ar[lo], &ar[j]);
        return j;
    }
    void sub(int ar[], int lo, int hi){
        int diff = hi - lo;
        if(diff){
            if(diff < 8){
                insertion_sort(ar, lo, hi);
                return;
            }
            int j = partition(ar, lo, hi);
            sub(ar, lo, j-1);
            sub(ar, j+1, hi);
        }
    }
    void sort(int ar[], int size){
        sub(ar, 0, size-1);
    }
}
namespace merge{
    void insertion_sortr(int *ar, int left,int right){		//Plain old insertion sort, in a range!
        int k,j,i,l = left;			
        for(i = left+1;i<=right;i++){
            k = ar[i];
            j = i-1;
            while(ar[j]>k && j>=l){
                ar[j+1] = ar[j];
                j--;
            }
            ar[j+1] = k;
        }
    }
    void merge(int* ar,int fl, int fr,int sr){ 
        int i,j,k;
        int n1 = fr-fl+1;
        int n2 = sr-fr;
        int* lar= new int [n1];
        int* rar = new int[n2];
        j=k=0;
        for(i=fl;i<=sr;i++){
            if(i<=fr){
                lar[j++] = ar[i];
            }
            else{
                rar[k++] = ar[i];
            }
        }
        j=k=0;
        for(i=fl;j<n1 && k<n2;i++){
            if(lar[j]<rar[k]){
                ar[i] = lar[j++];
            }
            else{
                ar[i] = rar[k++];
            }
        }
        if(k==n2){
            for(;i<=sr;i++){
                ar[i] = lar[j++];
            }
        }
        else{
            for(;i<=sr;i++){
                ar[i] = rar[k++];
            }
        }
        delete[] lar;
        delete[] rar;
    }
    void merge_sort(int* ar, int left, int right){
        if(right-left>50){		
            int mid = (left+right)/2;
            merge_sort(ar,left,mid);
            merge_sort(ar,mid+1,right);
            merge(ar,left,mid,right);
        }
        else{
            insertion_sortr(ar,left,right);
        }
        return;
    }
    void sort(int *ar, int size){
        merge_sort(ar, 0, size-1);
    }
}
NONIUS_BENCHMARK("quick::sort",[](nonius::chronometer meter){
        vint = {};
        vint.reserve(test_size);
        for(int i = 0; i < test_size; i++){
        vint.push_back(dist(mt));
        }
        meter.measure([]{
            quick::sort(&vint[0], test_size);
            });
        assert(std::is_sorted(vint.begin(), vint.end()));
        })
NONIUS_BENCHMARK("std::sort",[](nonius::chronometer meter){
        vint = {};
        vint.reserve(test_size);
        for(int i = 0; i < test_size; i++){
        vint.push_back(dist(mt));
        }
        meter.measure([]{
            std::sort(vint.begin(), vint.end());
            });
        assert(std::is_sorted(vint.begin(), vint.end()));
        })
NONIUS_BENCHMARK("merge::sort",[](nonius::chronometer meter){
        vint = {};
        vint.reserve(test_size);
        for(int i = 0; i < test_size; i++){
        vint.push_back(dist(mt));
        }
        meter.measure([]{
            merge::sort(&vint[0], test_size);
            });
        assert(std::is_sorted(vint.begin(), vint.end()));
        })

