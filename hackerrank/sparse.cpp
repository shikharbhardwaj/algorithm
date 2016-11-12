#include <algorithm>
#include <iostream>
#include <unordered_map>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::string temp;
    int N, Q;
    std::cin >> N;
    std::unordered_map<std::string, int> freq;
    for (int i = 0; i < N; i++) {
        std::cin >> temp;
        if (freq.find(temp) == freq.end()) {
            freq[temp] = 1;
        } else {
            freq[temp]++;
        }
    }
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        std::cin >> temp;
        if (freq.find(temp) == freq.end()) {
            std::cout << "0\n";
        } else {
            std::cout << freq[temp] << "\n";
        }
    }
}
