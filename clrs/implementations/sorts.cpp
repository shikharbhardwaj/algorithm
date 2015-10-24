#include <iostream>
#include <vector>
namespace algo{
    template<typename T>void swap(T &t1, T &t2){
        T temp = std::move(t1);
        t1 = std::move(t2);
        t2 = std::move(temp);
    }
    template   <typename iter,
               typename T = typename std::iterator_traits<iter>::value_type,
               typename comp = std::less<T>>
                   void insertion_sort(iter begin, iter end, comp comparator = comp()){
                       if(begin == end){
                           return;
                       }
                       T elem;
                       iter j;
                       for(iter cur = begin + 1; cur != end; cur++){
                           elem = std::move(*cur);
                           j = cur-1;
                           while(comparator(elem, *j) && j >= begin){
                               *(j+1) = std::move(*j);
                               j--;
                           }
                           *(j+1) = std::move(elem);
                       }
                   }
    //template   <typename iter,
               //typename T = typename std::iterator_traits<iter>::value_type,
               //typename comp = std::less<T>>
                   //void selection_sort(iter begin, iter end, comp comparator = comp()){
                       //if(begin == end){
                           //return;
                       //}
                       //for(iter i = begin; i != end; i++){
                           
                       //}
                   //}
    template<typename iter>void show(iter begin, iter end){
        for(iter i = begin; i != end; i++){
            std::cout<<*i<<" : ";
        }
    }
}
int main(){
    int ar[10] = {1,2,3,4,5,6,7,8,9,10};
    algo::insertion_sort(&ar[0], &ar[10]);
    algo::show(&ar[0], &ar[10]);
}
