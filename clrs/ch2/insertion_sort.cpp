#include <iostream>
#include <vector>
template    <typename iter, 
            typename T = typename std::iterator_traits<iter>::value_type, 
            typename comp = std::less<T>>
        void insertion_sort(iter begin, iter end, comp comparator = comp()){
            if (begin >= end){
                return;
            }
            T cur;
            iter j;
            for(iter i = begin + 1; i < end; i++){
                cur = std::move(*i);
                j = i - 1;
                while(comparator(cur, *j) > 0 && j >= begin){
                    *(j+1) = std::move(*j);
                    j--;
                }
                *(j+1) = std::move(cur);
            }
        }
int main(){
    std::vector<float> vec = {5.7,2.1,4.5,6.4};
    insertion_sort(vec.begin(), vec.end());
    for(auto elem : vec){
        std::cout<<elem<<" : ";
    }
    std::cout<<std::endl;
}
