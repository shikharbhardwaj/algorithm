#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif
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

struct INode {
    string name;
    int size;

    INode()
};

struct Dentry {
    string name;
    vector<INode> files;
    vector<Dentry*> directories;

    Dentry(string name_): name(name_) {}
};

vector<string> split(const string & input, char delim=' ') {
    istringstream ss(input);
    vector<string> tokens;
    string token;

    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
}

struct FileSystem {
    map<string, Dentry*> entries_by_path;

    Dentry* get_dentry(string path) {
        if (entries_by_path.find(path) != entries_by_path.end()) {
            return entries_by_path[path];
        }
        entries_by_path[path] = new Dentry(path);

        return entries_by_path[path];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif
    FileSystem fs;
    string current_dir = "/";

    string line;

    auto processChdir = [&](string input) {
        if (input == "..") {
            auto last_sep = find(current_dir.rbegin(), current_dir.rend(), '/').base();
            if (last_sep == begin(current_dir) || last_sep == next(begin(current_dir))) {
                current_dir = "/";
            } else {
                current_dir = string(begin(current_dir), prev(last_sep));
            }
        }
    };

    fs.get_dentry(current_dir);

    auto processLs = [&](vector<string>& entries) {
        for (auto entry : entries) {
            auto tokens = split(entry);
            if (tokens[0] == "dir") {
                fs.get_dentry(current_dir + "/" + tokens[1]);
            } else {
                int size = stoi(tokens[0]);
                int name = tokens[1];
                fs.get_dentry(current_dir)->files.emplace_back(name, size);
            }
        }
    };

    getline(cin, line);

    while (true) {
        auto tokens = split(line);

        if (tokens[1] == "cd") {
            processChdir(tokens[2]);
            getline(cin, line);
        } else if (tokens[1] == "ls") {
            vector<string> entries;

            while (!line.empty() && line[0] != '$') {
                entries.push_back(line);
                getline(cin, line);
            }

            processLs(entries);
        }

        if (!cin || line.empty()) {
            break;
        }
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}