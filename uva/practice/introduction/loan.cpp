#include <bits/stdc++.h>
int main() {
    int months, dep_records;
    float amount, down_pay;
    while (true) {

        std::cin >> months >> down_pay >> amount >> dep_records;
        if (months < 0) {
            break;
        }
        float dep_amounts[101] = {0};
        while (dep_records--) {
            int in;
            float drop;
            std::cin >> in >> drop;
            dep_amounts[in] = drop;
        }
        for (int i = 1; i < months; i++) {
            if (dep_amounts[i] == 0) {
                dep_amounts[i] = dep_amounts[i - 1];
            }
        }
        float car_value = down_pay + amount, owed = amount,
              emi = amount / months;
        car_value -= car_value * dep_amounts[0];
        int i;
        for (i = 1; i <= months && car_value < owed; i++) {
            car_value -= car_value * dep_amounts[i];
            owed -= emi;
        }
        i--;
        if (i == 1) {
            std::cout << "1 month";
        } else {
            std::cout << i << " months";
        }
        std::cout << "\n";
    }
}
