// Uva : 579
//
#include <cmath>
#include <iomanip>
#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::string in;
    float hour, min, h_deg, m_deg;
    while (true) {
        std::cin >> in;
        if (in == "0:00")
            break;
        else {
            if (in[1] == ':') {
                hour = std::stoi(in.substr(0, 1));
                min = std::stoi(in.substr(2, 2));
            } else {
                hour = std::stoi(in.substr(0, 2));
                min = std::stoi(in.substr(3, 2));
            }
            m_deg = min * 6;
            h_deg = hour * 30 + m_deg / 12;
            auto diff = fabs(h_deg - m_deg);
            if (diff > 180)
                diff = 360 - diff;
            std::cout << std::fixed << std::setprecision(3);
            std::cout << diff << "\n";
        }
    }
}
