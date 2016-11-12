#include <bits/stdc++.h>
int main() {
    int num_people, budget, num_hotels, weeks;
    while (std::cin >> num_people >> budget >> num_hotels >> weeks) {
        // Process each hotel
        int min_cost = -1, beds;
        int bed_price = 0;
        for (int i = 0; i < num_hotels; i++) {
            std::cin >> bed_price;
            int cur_cost = num_people * bed_price;
            if (num_people * bed_price > budget) {
                // Sorry
                for (int i = 0; i < weeks; i++) {
                    std::cin >> beds;
                }
            } else {
                for (int i = 0; i < weeks; i++) {
                    std::cin >> beds;
                    if (beds >= num_people) {
                        if (min_cost == -1) {
                            min_cost = cur_cost;
                        } else if (min_cost > cur_cost) {
                            min_cost = cur_cost;
                        }
                    }
                }
            }
        }
        if (min_cost == -1) {
            std::cout << "stay home\n";
        } else {
            std::cout << min_cost << "\n";
        }
    }
}
