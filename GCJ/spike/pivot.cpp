#include <bits/stdc++.h>
#include <random>

using namespace std;

int solve(const vector<int>& nums_, int k) {
    auto nums = nums_;
    std::random_device rd;
    std::mt19937 gen(rd());

    function<int(int, int)> find = [&](int l, int r) {
        std::uniform_int_distribution<int> dist(l, r - 1);
        auto pivot_idx = dist(gen);

        swap(nums[l], nums[pivot_idx]);

        int i = l + 1, j = r - 1;

        while (true) {
            while (i < r && nums[i] <= nums[l]) ++i;

            while (j > i && nums[j] > nums[l]) --j;

            if (j <= i) break;

            swap(nums[i++], nums[j--]);
        }

        // i - 1 will point to the location where the pivot can be placed.
        auto p = max(i - 1, l);
        
        swap(nums[p], nums[l]);

        if (p == k) return nums[p];
        else if (p < k) return find(p + 1, r);
        else return find(l, p);
    };

    return find(0, nums.size());
}


int main() {
    int ans = solve({1, 2, 3, 4}, 3);
    cout << ans << endl;
}