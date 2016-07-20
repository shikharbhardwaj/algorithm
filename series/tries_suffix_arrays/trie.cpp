#include <iostream>
const int alphabet_size = 26;
const char sentinel = 'a';
class trie {
  private:
    inline size_t char_to_i(char ch) { return ch - sentinel; }
    typedef struct trie_node {
        trie_node *children[alphabet_size];

        bool is_leaf; // Is this node a leaf
    } trie_node;
    trie_node *root;
    trie_node *new_node() {
        trie_node *new_node_ptr = new trie_node;
        for (auto &elem : new_node_ptr->children) {
            elem = nullptr;
        }
        return new_node_ptr;
    }

  public:
    void insert(const std::string &val) {
        size_t index;
        auto p_crawl = root;
        for (size_t level = 0; level < val.size(); level++) {
            index = char_to_i(val[level]);
            if (p_crawl->children[index] == nullptr) {
                p_crawl->children[index] = new_node();
            }
            p_crawl = p_crawl->children[index];
        }
        p_crawl->is_leaf = true;
    }
};
