#include <iostream>
#include <numeric>
#include <set>


int main() {
    std::set<int> max_so_far;

    while (std::cin) {
        int current = 0;

        std::string line = "line";

        while (std::cin && !line.empty()) {
            std::getline(std::cin, line, '\n');

            if (!line.empty()) current += std::stoi(line);
        }

        max_so_far.insert(current);
        
        if (max_so_far.size() > 3) max_so_far.erase(max_so_far.begin());
    }

    std::cout << std::accumulate(begin(max_so_far), end(max_so_far), 0) << std::endl;
}