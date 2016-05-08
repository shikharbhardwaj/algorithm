/* DataStructs - Implementations by Shikhar Bhardwaj, <shikharbhardwaj68@gmail.com>
 *
 * Simple implementations of elementary data structures,
 * Licensed under the DWTFYWTL. All rights reversed.
 */
#include <vector>
#include <type_traits>
#include <iostream>
#include <deque>
namespace DataStructs{
    template <typename T> class Stack{
        private:
            std::vector<T> keeper;
        public:
            Stack() = default;  //Default constructor
            Stack(int n, const T& elem){    //Fill the stack with N (elems)
                for(int i = 0 ;i < n;i++){
                    keeper.push_back(elem);
                }
            }
            Stack(int n){
                for(int i = 0;i < n;i++){
                    keeper.push_back(T());
                }
            }
            Stack(const std::vector<T>& copy){
                keeper = copy;
            }
            Stack(const Stack& copy){
                keeper = copy.keeper;
            }
            Stack& operator=(const Stack& copy){
                keeper = copy.keeper;
            }
            void pop(){
                if(keeper.empty() == false){
                    keeper.pop_back();
                }
            }
            void push(const T& elem){
                keeper.push_back(elem);
            }
            T get_top(){
                if(keeper.empty() == false){
                    return keeper[keeper.size()-1];
                }
                else{  //We're in error!
                    assert(keeper.empty());
                }
            }
    };
    template <typename T> class Queue{
        //The queue cannot be implemented as a contiguous storage because : 
        //The random access iterators need to provide a way to remove the element from the front and the back 
        //isotropically. So we need a linked list. 
        //But linked list traversal is expensive. So make this : allocate contiguous blocks of data depending upon
        //the base type. Maintain an inventory of the data kept in them. Profit!
        //This is too much to implement here. Use std::deque
    };

}
void display_deque(const std::deque<int> &d){
   for(auto elem : d){ //Simple deque traversal
        std::cout<<elem<<" : ";
    }
    std::cout<<std::endl;
}
int main(){
    const int i = 10;
    std::cout<<std::boolalpha<<std::is_const<decltype(i)>::value;
}
