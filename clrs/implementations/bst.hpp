#ifndef BST_INCLUDED
#define BST_INCLUDED
#include <memory>
#include <initializer_list>
//An implementation of a persistent binary search tree
//
template <typename T>
class bst{
    struct node;
    typedef std::unique_ptr<node> node_ptr;
    node_ptr root; 
    struct node{
        T data;
        node_ptr left;
        node_ptr right;
        node() = default;
        node(const T& data, node_ptr &&left, node_ptr &&right) : 
            data(data), left(std::move(left)), right(std::move(right)) {}
    };
public:
    bst() = default;
    bst(std::initializer_list<const T&>);
    void insert(const T& data);
    T minimum();
    T maximum();
    std::shared_ptr<node> search(const T& data);
};
template <typename T>
T bst<T>::minimum(){
    T min;
    std::shared_ptr<node> cur_node = root;
    while(cur_node != nullptr){
        min = cur_node->data;
        cur_node = cur_node->left;
    }
    return min;
}
template <typename T>
T bst<T>::maximum(){
    T max;
    std::shared_ptr<node> cur_node = root;
    while(cur_node != nullptr){
        max = cur_node->data;
        cur_node = cur_node->right;
    }
    return max;
}
template <typename T>
std::shared_ptr<typename bst<T>::node> bst<T>::search( const T& data ){
    std::shared_ptr<node> result = root;
    while(result != nullptr){
        if(result->data == data){
            break;
        }
        else if(result->data > data){
            result = result->left;
        }
        else{
            result = result->right;
        }
    }
    return result;
}
#endif
