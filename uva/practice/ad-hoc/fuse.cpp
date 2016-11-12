#include <cstring>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, m, c;
    int consumption[21];
    int seq = 1;
    while (true) {
        int sum = 0, id, max_sum = 0;
        bool blown = false;
        bool status[21];
        std::cin >> n >> m >> c;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++) {
            std::cin >> consumption[i];
            status[i] = false;
        }
        for (int i = 0; i < m; i++) {
            std::cin >> id;
            id--;
            if (status[id]) {
                status[id] = false;
                sum -= consumption[id];
            } else {
                status[id] = true;
                sum += consumption[id];
                if (max_sum < sum)
                    max_sum = sum;
                if (sum > c)
                    blown = true;
            }
        }
        std::cout << "Sequence " << seq << "\n";
        if (blown) {
            std::cout << "Fuse was blown.\n\n";
        } else {
            std::cout << "Fuse was not blown.\n";
            std::cout << "Maximal power consumption was " << max_sum
                      << " amperes.\n\n";
        }
        seq++;
    }
}
