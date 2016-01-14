#include <vector>
#include <cassert>
#include <algorithm>
#include <iterator>
template <typename iter, 
         typename T = typename std::iterator_traits<iter>::value_type, 
         class comp = std::less<T>>
void selection_sort(iter begin, iter end){
    iter min = begin;
    for(; begin != end - 1; begin++){
        iter cur = begin + 1;
        for(; cur != end;cur++){
            if(*cur < *min){
                min = cur;
            }
        }
        *begin = *min;
    }
}
int main(){
    std::vector<int> lol = {4,6,7,8,9};
}
