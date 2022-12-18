#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif
#include <sstream>
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)
#define ALL(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

vector<string> split(const string& str, char delim=' ') {
    istringstream ss(str);
    string token;
    vector<string> tokens;

    while (getline(ss, token, delim)) {
        if (token.empty()) continue;
        tokens.push_back(token);
    }

    return tokens;
}

struct Point2D {
    int x, y;

    Point2D(int x_, int y_) : x(x_), y(y_) {}
};
ostream& operator<<(ostream& os, const Point2D& point) {
    return os << "Point2D(x=" << point.x << ", y=" << point.y << ")";
}

int parse_coordinate(string coordinate_str) {
    auto start_it = next(find(begin(coordinate_str), end(coordinate_str), '='));
    auto end_it = find_if(start_it, end(coordinate_str), [](char ch) { return ch == ':' || ch == ','; });
    auto num = string{ start_it, end_it };
    return stoi(num);
}

int dist(const Point2D& p0, const Point2D& p1) {
    return abs(p1.x - p0.x) + abs(p1.y - p0.y);
}

pii intersect(const pii& p0, const pii& p1) {
    return {max(p0.first, p1.first), min(p0.second, p1.second)};
}

bool overlaps(const pii& p0, const pii& p1) {
    auto intersection = intersect(p0, p1);
    return intersection.first <= intersection.second;
}

pii combine(const pii& p0, const pii& p1) {
    return {min(p0.first, p1.first), max(p0.second, p1.second)};
}

vector<pair<Point2D, Point2D>> parse_sensors() {
    vector<pair<Point2D, Point2D>> sensors;

    string line;
    while (getline(cin, line) && !line.empty()) {
        auto tokens = split(line);
        Point2D sensor_location(parse_coordinate(tokens[2]), parse_coordinate(tokens[3]));
        Point2D beacon_location(parse_coordinate(tokens[8]), parse_coordinate(tokens[9]));
        sensors.emplace_back(sensor_location, beacon_location);
    }

    return sensors;
}

map<int, int> get_beacon_counts_by_x(const vector<pair<Point2D, Point2D>>& sensors, int target_y) {
    set<pair<int, int>> beacons;
    transform(begin(sensors), end(sensors), inserter(beacons, beacons.begin()), [](const pair<Point2D, Point2D>& p) {
        return make_pair(p.second.x, p.second.y);
    });

    map<int, int> beacon_counts_by_x;
    for (auto beacon : beacons) {
        if (beacon.second == target_y) {
            beacon_counts_by_x[beacon.first] += 1;
        }
    }

    int prefix_sum = 0;
    for (auto& [x, val] : beacon_counts_by_x) {
        prefix_sum += val;
        val = prefix_sum;
    }

    if (beacon_counts_by_x.empty()) {
        beacon_counts_by_x[0] = 0;
    }

    return beacon_counts_by_x;
}


int beacon_count_in_x_range(int x_min, int x_max, const map<int, int>& beacon_counts_by_x) {
    auto range_start = beacon_counts_by_x.lower_bound(x_min);
    int beacon_count = 0;
    if (range_start != beacon_counts_by_x.begin()) {
        beacon_count -= prev(range_start)->second;
    }

    auto range_end = beacon_counts_by_x.lower_bound(x_max);

    if (range_end == beacon_counts_by_x.begin() && range_end->first > x_max) {
    } else if (range_end != beacon_counts_by_x.end()) {
        if (range_end->first == x_max) {
            beacon_count += range_end->second;
        } else {
            beacon_count += prev(range_end)->second;
        }
    } else {
        beacon_count += beacon_counts_by_x.rbegin()->second;
    }

    return beacon_count;
}

void solve_part1() {
    vector<pair<Point2D, Point2D>> sensors = parse_sensors();
    const int target_y = 2000000;
    auto beacon_counts_by_x = get_beacon_counts_by_x(sensors, target_y);


    vector<pair<int, int>> ranges;

    // All points which are <= the manhattan distance of a sensor and its beacon are not beaons.
    for (auto [sensor, beacon] : sensors) {
        int d = dist(sensor, beacon);
        int y_dist = abs(sensor.y - target_y);

        if (y_dist > d) continue;
        int target_d = d - y_dist;

        cout << "Sensor: " << sensor << " beacon: " << beacon << " dist: " << d << endl;
        cout << "Target distance: " << target_d << endl;

        int x_max = target_d + sensor.x;
        int x_min = sensor.x;

        if (x_max >= x_min) {
            cout << "Adding range: " << make_pair(x_min, x_max) << endl;
            ranges.emplace_back(x_min, x_max);
        }

        x_max = sensor.x - 1;
        x_min = sensor.x - target_d;

        if (x_max >= x_min) {
            cout << "Adding range: " << make_pair(x_min, x_max) << endl;
            ranges.emplace_back(x_min, x_max);
        }
    }

    sort(ALL(ranges));
    cout << ranges << endl;

    int ans = 0;
    pair<int, int> cur_interval = ranges[0];

    for (int i = 1; i < ranges.size(); ++i) {
        if (overlaps(cur_interval, ranges[i])) {
            cur_interval = combine(cur_interval, ranges[i]);
        } else {
            ans += cur_interval.second - cur_interval.first + 1;
            ans -= beacon_count_in_x_range(cur_interval.first, cur_interval.second, beacon_counts_by_x);
            cur_interval = ranges[i];
        }
    }
    cout << "Final range: " << cur_interval << endl;
    cout << "Left or right: " << make_pair(cur_interval.first + target_y, cur_interval.second - target_y) << endl;
    ans += cur_interval.second - cur_interval.first + 1;
    ans -= beacon_count_in_x_range(cur_interval.first, cur_interval.second, beacon_counts_by_x);

    cout << ans << endl;
    cout << sensors << endl;
}

void solve_part2() {
    auto sensors = parse_sensors();

    const int max_x = 4000000, max_y = 4000000;
    const int min_x = 0, min_y = 0;

    int left = 0, right = max_y;

    auto find_breakpoint = [&](int target_y, bool print_range = false) {
        auto beacon_counts_by_x = get_beacon_counts_by_x(sensors, target_y);
        vector<pii> ranges;

        for (auto [sensor, beacon] : sensors) {
            int d = dist(sensor, beacon);
            int y_dist = abs(sensor.y - target_y);

            if (y_dist > d) continue;
            int target_d = d - y_dist;

            int x_max = target_d + sensor.x;
            int x_min = sensor.x;

            if (x_max >= x_min) {
                ranges.emplace_back(x_min, x_max);
            }

            x_max = sensor.x - 1;
            x_min = sensor.x - target_d;

            if (x_max >= x_min) {
                ranges.emplace_back(x_min, x_max);
            }
        }

        sort(ALL(ranges));
        pair<int, int> cur_interval = ranges[0];

        int smallest_overlap = ranges.back().second - ranges[0].first;

        for (int i = 1; i < ranges.size(); ++i) {
            if (overlaps(cur_interval, ranges[i])) {
                auto intersection = intersect(cur_interval, ranges[i]);
                smallest_overlap = min(smallest_overlap, intersection.second - intersection.first + 1);
                cur_interval = combine(cur_interval, ranges[i]);
            } else {
                if (cur_interval.second + 1 < ranges[i].first) {
                    cout << "Broke at: y=" << target_y << " " << cur_interval << " " << ranges[i] << endl;
                    cout << "Ans = " << (ull(max_x) * (cur_interval.second + 1) + target_y) << endl;
                    return true;
                }
                cur_interval = ranges[i];
            }
        }

        return false;
    };

    // while (left < right) {
    //     int mid = left + (right - left) / 2;
    //     if (go_left(mid)) {
    //         right = mid;
    //     } else {
    //         left = mid + 1;
    //     }
    // }


    for (int i = 0; i < max_y; ++i) {
        if (find_breakpoint(i)) {
            break;
        }
    }

    // go_left(left - 1, true);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in2.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif
/*
874397
1622698

*/
    // solve_part1();
    solve_part2();
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}