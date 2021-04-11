#include <bits/stdc++.h>

using namespace std;

class LFUCache {
    struct Item {
        int key, val;

        Item(int k, int v) : key(k), val(v) {}
    };

    private:
    size_t capacity_, min_freq_;

    unordered_map<int, list<Item>> items_by_freq_;
    unordered_map<int, int> freq_by_key_;
    unordered_map<int, list<Item>::iterator> iters_by_key_;

    int get_key_to_evict() {
        return items_by_freq_[min_freq_].back().key;
    }

    void evict() {
        int key = get_key_to_evict();

        cout << "Evicting " << key << endl;
        cout << "Min freq " << min_freq_ << endl;

        auto it = iters_by_key_[key];
        auto cur_freq = freq_by_key_[key];
        cout << "Freq: " << cur_freq << endl;

        items_by_freq_[cur_freq].erase(it);
        cout << "Items" << endl;
        freq_by_key_.erase(key);
        cout << "Freq" << endl;
        iters_by_key_.erase(key);
        cout << "Iters" << endl;

        if (items_by_freq_[cur_freq].empty()) {
            items_by_freq_.erase(cur_freq);
        }
    }

    public:
    LFUCache(int capacity) : capacity_(capacity), min_freq_(1) {
    }

    int get(int key) {
        if (iters_by_key_.find(key) == iters_by_key_.end()) {
            cout << "Done get" << endl;
            return -1;
        }

        auto it = iters_by_key_[key];
        auto item = *it;

        int cur_freq = freq_by_key_[key];
        freq_by_key_[key] = cur_freq + 1;

        items_by_freq_[cur_freq].erase(it);
        items_by_freq_[cur_freq + 1].push_front(item);
        iters_by_key_[key] = begin(items_by_freq_[cur_freq + 1]);

        if (items_by_freq_[cur_freq].empty()) {
            items_by_freq_.erase(cur_freq);

            if (cur_freq == min_freq_) {
                min_freq_ = cur_freq + 1;
            }
        }

        cout << "Done get" << endl;
        return item.val;
    }

    void set(int key, int val) {
        if (iters_by_key_.find(key) != iters_by_key_.end()) {
            auto it = iters_by_key_[key];
            it->val = val;

            // Bring it to the front.
            int cur_freq = freq_by_key_[key];
            items_by_freq_[cur_freq].erase(it);
            items_by_freq_[cur_freq + 1].emplace_front(key, val);
            iters_by_key_[key] = begin(items_by_freq_[cur_freq + 1]);
            freq_by_key_[key] = cur_freq + 1;

            if (items_by_freq_[cur_freq].empty()) {
                items_by_freq_.erase(cur_freq);

                if (cur_freq == min_freq_) {
                    min_freq_ = cur_freq + 1;
                }
            }
        } else {
            if (iters_by_key_.size() == capacity_) {
                evict();
                cout << "Evicted" << endl;
            }

            int cur_freq = 1;
            items_by_freq_[cur_freq].emplace_front(key, val);
            auto it = begin(items_by_freq_[cur_freq]);
            iters_by_key_[key] = it;
            freq_by_key_[key] = cur_freq;

            min_freq_ = cur_freq;
        }
        cout << "Done set" << endl;
    }

};


/*

least_frequent() -> Get the key which was used least number of times.

unordered_map<int, List<Key>>      -> Map of frequency to the list of keys with that frequency.
unordered_map<Key, int>            -> Map of key to frequency.
unordered_map<Key, List::Iterator> -> To move around keys from one frequency to another in O(1)

1. get -> Update frequency for the key, move item from freq1 -> freq2 , update min_frequency.
2. set -> If size > limit, evict, ow insert.
*/


int main() {
    LFUCache cache(1);

    cache.set(2, 1);
    cache.set(2, 1);

    cache.get(3);
    cache.get(0);

    cache.set(3, 6);
}