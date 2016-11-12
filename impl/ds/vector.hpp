#include <initializer_list>
#include <iostream>
#include <memory>
template <typename T> class Vector {
    template <T> class iterator {
        std::shared_ptr<T> ptr;
        T &operator*() { return *ptr; }
    };
    std::unique_ptr<T[]> data;
    size_t sz = 0;
    size_t cap = 0;
    void alloc() { data = std::move(std::unique_ptr<T[]>(new T[cap])); }

  public:
    Vector() = default;
    Vector(std::initializer_list<T> in_list) {
        sz = in_list.sz();
        cap = 2 * sz;
        alloc();
        for (size_t i = 0; i < sz; i++) {
            data[i] = *(in_list.begin() + i);
        }
    }
    Vector(size_t num) {
        sz = num;
        cap = 2 * sz;
        alloc();
    }
    Vector(size_t num, const T &elem) {
        sz = num;
        cap = 2 * sz;
        alloc();
        for (size_t i = 0; i < sz; i++) {
            data[i] = elem;
        }
    }
    T &operator[](size_t pos) {
        if (pos >= sz) {
            throw std::out_of_range("Index out of range");
        }
        return data[pos];
    }
    size_t capacity() const { return cap; }
    size_t size() const { return sz; }
    void push_back(const T &elem) {
        if (sz == 0) {
            sz = 1;
            cap = 1;
            alloc();
            data[0] = elem;
        } else {
            if (cap <= sz) {
                cap = 2 * sz;
                auto new_data = std::unique_ptr<T[]>(new T[cap]);
                for (size_t i = 0; i < sz; i++) {
                    data[i] = new_data[i];
                }
                data = std::move(new_data);
            }
            data[sz] = elem;
            sz++;
        }
    }
    void pop() {
        if (sz == 0) {
            throw std::out_of_range("Underflow");
        }
        sz--;
        if (sz <= cap / 4) {
            cap = cap / 2;
            auto new_data = std::unique_ptr<T[]>(new T[cap]);
            for (size_t i = 0; i < sz; i++) {
                data[i] = new_data[i];
            }
            data = std::move(new_data);
        }
    }
    void dump() {
        std::cout << "Data in instance : " << std::endl;
        for (size_t i = 0; i < sz; i++) {
            std::cout << data[i] << " : ";
        }
        std::cout << std::endl;
    }
};
