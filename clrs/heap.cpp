#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
class max_heap{
    private:
        std::vector<int> tree;
        inline int left(int i){
            return 2*i + 1; 
        }
        inline int right(int i){
            return 2*(i+1);
        }
        inline int parent(int i){
            if(i%2){
                return i/2;
            }
            return i/2 - 1;
        }
        inline int max(int x, int y){
            return (x>y)?x:y;
        }
        inline void swap(int *a, int *b){
            int t = *a;
            *a = *b;
            *b = t;
        }
        bool is_max_heap(){
            int leave = tree.size()/2; 
            for(int i = leave;i >= 0;i--){ //Traverse the tree
                if(tree[i] > tree[parent(i)]){
                    return false;
                }
            }
            return true;
        }
    public:
        max_heap(int n){
            for(int i = 0;i<n;i++){
                tree.push_back(i);
            }
        }
        max_heap(const std::vector<int> &v){
            tree = v;
        }
        void max_heapify(size_t i){
            size_t l = left(i);
            size_t r = right(i);
            size_t largest;
            if(l < tree.size() && tree[l] > tree[i]){
                largest = l;
            }
            else{
                largest = i;
            }
            if(r < tree.size() && tree[r] > tree[largest]){
                largest = r;
            }
            if(largest != i){
                swap(&tree[i], &tree[largest]);
                max_heapify(largest); //Establish heap property in the subtrees
            }
        }
        void to_string(){
            for(auto elem : tree){
                std::cout<<" : "<<elem;
            }
            std::cout<<"\n";
        }
        void build_max_heap(){
            for(int i = tree.size()/2 - 1; i >= 0; i--){
                max_heapify(i);
            }
            assert(is_max_heap()); //Check if the heap is correctly established
        }
        inline int size(){
            return tree.size();
        }
        int root(){
            return tree[0];
        }
        void sort(){
            while(tree.size()){
                std::cout<<" : "<<tree[0];
                std::swap(tree[0], tree[tree.size()-1]);
                tree.pop_back();
                max_heapify(0);
            }
        }
};
int main(){
    max_heap h1({4,1,3,2,16,9,10,14,8,7});
    h1.build_max_heap();
    h1.sort();
}
