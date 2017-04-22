#include <array>
#include <iostream>
#include <vector>

const int stores = 3;
struct field {
    int val, n;
    field() = default;
    field(int _val, int _n) : val(_val), n(_n) {}
    field &operator++() {
        val += 1;
        if (val > n) {
            val -= n;
        }
        return *this;
    }
    field operator++(int) {
        field result(*this);
        ++(*this);
        return result;
    }
    field &operator--() {
        val -= 1;
        if (val < 0) {
            val += n;
        }
        return *this;
    }
    field operator--(int) {
        field result(*this);
        --(*this);
        return result;
    }
};
template <typename ValType> class data_store {
  private:
    std::vector<std::array<ValType, stores>> nodes;
    std::vector<bool> check;

  public:
    data_store() = default;
    data_store(size_t n) {
        nodes.assign(n, {{0, 0, 0}});
        check.assign(n, true);
    }
    void corrupt(size_t i) { check[i] = false; }
    void store(size_t i, ValType val) { nodes[i][0] = val; }
};

int main() {
    // Implement data redundant data retrieval system
}
