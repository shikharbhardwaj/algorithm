#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#include <prettyprint/prettyprint.hpp>

using namespace std;

int get_priority(char item) {
    int priority = 0;

    if (isupper(item)) {
        priority += 26;
    }

    char lower_item = tolower(item);

    return priority + lower_item - 'a' + 1;
}

void solve_part_a() {
    int answer = 0;
    string contents;

    while (cin >> contents) {
        auto n = contents.size();
        auto mid_it =  next(begin(contents), n / 2);
        auto first_compartment = set<char>(begin(contents), mid_it);
        auto second_compartment = set<char>(mid_it, end(contents));

        vector<char> common;

        set_intersection(begin(first_compartment),
                         end(first_compartment), begin(second_compartment),
                         end(second_compartment), back_inserter(common));
        if (common.empty()) {
            throw std::logic_error("Did not find a common item between two compartments.");
        }

        answer += get_priority(common[0]);
    }

    cout << answer << endl;
}

void solve_part_b() {
    int answer = 0;
    string contents;
    vector<set<char>> current_group;

    while (cin >> contents) {
        current_group.emplace_back(set<char>(begin(contents), end(contents)));

        if (current_group.size() == 3) {
            // Find the intersection between the 3 sets.
            set<char> common, common2;

            set_intersection(begin(current_group[0]),
                         end(current_group[0]), begin(current_group[1]),
                         end(current_group[1]), inserter(common, common.begin()));
            set_intersection(begin(current_group[2]),
                         end(current_group[2]), begin(common),
                         end(common), inserter(common2, common2.begin()));

            answer += get_priority(*common2.begin());
            current_group.clear();
            // cout << common2 << endl;
        }
    }

    cout << answer << endl;
}

int main() {
    // solve_part_a();
    solve_part_b();
}