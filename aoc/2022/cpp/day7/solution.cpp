#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <numeric>
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

    INode() {}
    INode(string name_, int size_) : name(name_), size(size_) {}
};

struct Dentry {
    private:
    map<string, INode> files;
    map<string, Dentry*> directories;

    public:
    string name;
    int size;

    Dentry(string name_): name(name_) {}

    void update_size() {
        for (auto [_, dir] : directories) {
            dir->update_size();
        }
        size = accumulate(begin(files), end(files), 0, [](int cur, const pair<string, INode>& inode) {
            return cur + inode.second.size;
        });
        size += accumulate(begin(directories), end(directories), 0, [](int cur, const pair<string, Dentry*>& dentry) {
            return cur + dentry.second->size;
        });
    }

    void update_dentry(const string& name, Dentry* dentry) {
        directories[name] = dentry;
    }

    void update_inode(const string& name, int size) {
        files[name] = INode(name, size);
    }

    vector<INode> getInodes() const {
        vector<INode> inodes;
        transform(begin(files), end(files), back_inserter(inodes), [](const pair<string, INode>& entry) {
            return entry.second;
        });

        return inodes;
    }
    vector<Dentry*> getDentries() const {
        vector<Dentry*> dentries;
        transform(begin(directories), end(directories), back_inserter(dentries), [](const pair<string, Dentry*>& entry) {
            return entry.second;
        });
        return dentries;
    }

    friend ostream& operator<< (ostream& os, const Dentry& dentry);
};

ostream& operator<< (ostream& os, const Dentry& dentry) {
    for (auto [_, file] : dentry.files) {
        os << file.size << "\t" << file.name << endl;
    }

    for (auto [_, dir] : dentry.directories) {
        os << dentry.name << endl;
    }

    return os;
}

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

    string join(const string& path0, const string& path1) {
        string ans;
        if (path1 == "..") {
            auto last_sep = find(path0.rbegin(), path0.rend(), '/').base();
            if (last_sep == begin(path0) || last_sep == next(begin(path0))) {
                ans = "/";
            } else {
                ans = string(begin(path0), prev(last_sep));
            }
        } else {
            ans = path0 +  string(path0.back() != '/', '/') + path1;
        }

        return ans;
    }

    void printTree(Dentry* cur, int indent=0) {
        if (cur == nullptr) {
            throw std::invalid_argument("cannot print tree for null Dentry");
        }

        if (cur->name == "/") {
            cout << cur->name << " " << cur->size << endl;
        }

        string pref = string(indent, ' ');

        for (auto file : cur->getInodes()) {
            cout << pref << " " << file.size << "\t" << file.name << endl;
        }

        for (auto dir : cur->getDentries()) {
            cout << dir->name << "\t" << dir->size << endl;
            printTree(dir, indent + 4);
        }
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
        if (input[0] != '/') current_dir = fs.join(current_dir, input);
        else current_dir = input;
    };

    fs.get_dentry(current_dir);

    auto processLs = [&](vector<string>& entries) {
        auto current_dentry = fs.get_dentry(current_dir);
        for (auto entry : entries) {
            auto tokens = split(entry);
            if (tokens[0] == "dir") {
                auto new_dentry = fs.get_dentry(fs.join(current_dir, tokens[1]));
                current_dentry->update_dentry(tokens[1], new_dentry);
            } else {
                int size = stoi(tokens[0]);
                string name = tokens[1];
                current_dentry->update_inode(name, size);
            }
        }
    };

    getline(cin, line);

    while (true) {
        cout << "Processing: " << line << endl;
        auto tokens = split(line);

        if (tokens[1] == "cd") {
            processChdir(tokens[2]);
            getline(cin, line);
            cout << "Current dir: " << current_dir << endl;
        } else if (tokens[1] == "ls") {
            vector<string> entries;

            do {
                getline(cin, line);
                entries.push_back(line);
            } while (cin && !line.empty() && line[0] != '$');
            
            entries.pop_back();

            cout << entries << endl;
            processLs(entries);
        }

        if (!cin || line.empty()) {
            break;
        }
    }

    fs.entries_by_path["/"]->update_size();
    fs.printTree(fs.entries_by_path["/"]);

    const int cutoff_size = 100000;

    int ans = 0;

    vector<pair<int, string>> dentries_by_size;

    for (auto [path, entry] : fs.entries_by_path) {
        if (entry->size <= cutoff_size) {
            ans += entry->size;
        }
        dentries_by_size.emplace_back(entry->size, path);
    }
    
    cout << ans << endl;

    const int total_available_size = 70000000;
    const int min_free_size = 30000000;

    const int current_used_size = fs.entries_by_path["/"]->size;

    int current_free_size = total_available_size - current_used_size;
    int needed_size = min_free_size - current_free_size;

    cout << "Needed: " << needed_size << endl;

    sort(ALL(dentries_by_size));
    auto candidate = lower_bound(ALL(dentries_by_size), make_pair(needed_size, string("")));

    if (candidate == end(dentries_by_size)) {
        throw std::logic_error("Could not find a dir which satisfies the constaints.");
    }

    cout << dentries_by_size << endl;

    cout << candidate->first << " " << candidate->second;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}