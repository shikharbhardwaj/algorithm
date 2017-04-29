#include <iostream>
#include <vector>
class BinarySearchTree{
    std::vector<int> v1;
    void establishSearchProperty(){
        
    }
    public:
    BinarySearchTree() = default;
    BinarySearchTree(int n){
        while(n--){
            v1.push_back(0);
        }
        establishSearchProperty();
    }
};
int main(){

}
