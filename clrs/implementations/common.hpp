#include <iostream>
#include <random>
#include <type_traits>
namespace algo{
    std::random_device rng;
    std::mt19937 gen(rng());
    std::uniform_int_distribution<int> dist;
    template<typename iter>void show(iter begin, iter end){
        for(iter i = begin; i != end; i++){
            std::cout<<*i<<" : ";
        }
    }
    template <typename iter, typename T = typename std::iterator_traits<iter>::value_type>
    typename std::enable_if<std::is_integral<T>::value, void>::type
    fill_random(iter begin, iter end){
        assert(begin <= end);
        for(iter i = begin; i != end; i++){
            *i = dist(gen);
        }
    }
}
