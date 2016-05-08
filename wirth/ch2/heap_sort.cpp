#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
//A simple implementation of a heapsort
//
template <typename T>
class heap {
private:
    std::vector<T> tree;
public:
    heap() = default;
    heap(const heap &other)             : tree { other.tree }   {}
    heap(heap &&other)                  : tree { other.tree }   {}
    heap& operator=(const heap& other) {
        if( &other != this ) {
            this->tree = std::move(other.tree);
        }
        return *this;
    }
    heap& operator=(heap&& other) {
        this->tree = { other.tree };
        return *this;
    }
    heap(const std::vector<T> &other) {
        tree = std::vector<T>(other.size() + 1); //Waste space
        size_t index = 1;
        for(auto elem : other){
            tree[index++] = elem;
        }
    }
    //max_heapify : takes the index and establishes the max_heap property
    //              at that index, assuming the heaps rooted at the children
    //              are already max heaps.
    void max_heapify(size_t index) {
        if( 2*index >= tree.size() ) {
            return;
        }
        else if( 2*index + 1 == tree.size() ) {
            if(tree[2*index] > tree[index]){
                std::swap(tree[index], tree[2*index]);
            }
        }
        else {
            int max_index = index;
            if(tree[2*index] > tree[index]) {
                max_index = 2*index;
            }
            if(tree[2*index + 1] > tree[max_index]) {
                max_index = 2*index + 1;
            }
            if(max_index != index) {
                std::swap(tree[max_index], tree[index]);
                max_heapify(max_index);
            }
        }
    }
    void build() {
        for(int index = std::round(tree.size()/2); index >= 1; index--){
            max_heapify(index);
        }
    }
    void show(){
        for(auto elem : tree){
            std::cout<<" : "<<elem;
        }
    }
};
int main() {
    std::vector<int> lol = {1,2,3,4,5,6,7};
    heap<int> sample(lol);
    sample.build();
    sample.show();      //Works
}

