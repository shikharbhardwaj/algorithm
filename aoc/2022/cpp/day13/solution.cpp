#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
#include <charconv>
#include <variant>
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

enum class NodeType {
    INT = 0,
    LIST
};

struct Node {
    int value;
    vector<shared_ptr<Node>> children;
    NodeType type = NodeType::INT;

    Node(int value_) : value(value_) {}
    Node(int value_, NodeType type_) : value(value_), type(type_) {}
};

ostream& operator<<(ostream& os, const Node& node) {
    os << "Node(value=" << node.value << ", type=" << (int) node.type << ", children=[";
    for (auto n : node.children) {
        os << *n << " ";
    }
    os << "])";

    return os;
}

template <class T, class... Args>
void from_chars_throws(const char* first, const char* last, T &t, Args... args) {
    std::from_chars_result res = std::from_chars(first, last, t, args... );

    // These two exceptions reflect the behavior of std::stoi.
    if (res.ec == std::errc::invalid_argument) {
        throw std::invalid_argument{"invalid_argument"};
    }
    else if (res.ec == std::errc::result_out_of_range) {
        throw std::out_of_range{"out_of_range"};
    }
}


int parseElement(string_view remaining) {
    auto final = find_if(begin(remaining), end(remaining), [](char ch) {
        return !isdigit(ch);
    });

    int res;
    from_chars_throws(begin(remaining), final, res);

    return res;
}

using Token = std::variant<int, string>;

struct Tokenizer {
    private:
    string input;
    optional<Token> last_token;
    int pos = 0;

    Token consume() {
        while (pos < input.size() && isspace(input[pos])) ++pos;

        switch (input[pos]) {
            case '[': ++pos; return "[";
            case ']': ++pos; return "]";
            case ',': ++pos; return ",";
            default:
                auto next_it = find_if(begin(input) + pos, end(input), [](char ch) {
                    return !isdigit(ch);
                });

                int res = stoi(string{begin(input) + pos, next_it});
                pos = distance(begin(input), next_it);

                return Token(res);
        }
    }

    public:
    Tokenizer(const string& input_) : input(input_) {}

    bool is_empty() {
        return !last_token.has_value() && pos == input.length();
    }

    Token peek() {
        if (last_token.has_value()) return last_token.value();

        last_token = consume();
        return last_token.value();
    }

    Token pop() {
        if (last_token.has_value()) {
            auto val = last_token.value();
            last_token.reset();
            return val;
        } else {
            auto token = peek();
            last_token.reset();
            return token;
        }
    }

    string get_location() {
        return to_string(pos);
    }

    friend ostream& operator<<(ostream& os, const Tokenizer& tok);
};

ostream& operator<<(ostream& os, const Tokenizer& tok) {
    return os << "Tokenizer(input=" << tok.input << ", pos=" << tok.pos << ")";
}

// helper type for the visitor #4
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
// explicit deduction guide (not needed as of C++20)
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

void parseLine(Node* parent, Tokenizer& tokenizer) {
    // cout << "Called with: " << parent->value << " : " << tokenizer << endl;

    bool seen_first_bracked = false;
    bool done = false;

    while (!done && !tokenizer.is_empty()) {
        auto token = tokenizer.peek();

        std::visit(
            overloaded {
                [&](const string& token) {
                    if (token == "[" && !seen_first_bracked) {
                        seen_first_bracked = true;
                        tokenizer.pop();
                    } else if (token == "]") {
                        tokenizer.pop();
                        done = true;
                    } else if (token == "[") {
                        auto curNode = make_shared<Node>(0, NodeType::LIST);
                        parseLine(curNode.get(), tokenizer);
                        parent->children.emplace_back(curNode);
                    } else if (token == ",") {
                        tokenizer.pop();
                    } else {
                        throw std::logic_error("Encountered unexpected token: " + token + " at location: " + tokenizer.get_location());
                    }
                },
                [&](int val) {
                    parent->children.emplace_back(make_shared<Node>(val));
                    tokenizer.pop();
                },
            }, token
        );
    }
}

bool operator<(Node l, Node r) {
    function<int(Node*, Node*)> isOrdered = [&](Node* l, Node* r) -> int {
        if (l->type == NodeType::INT && r->type == NodeType::LIST) {
            auto dummy = make_shared<Node>(0, NodeType::LIST);
            dummy->children.emplace_back(make_shared<Node>(l->value));
            return isOrdered(dummy.get(), r);
        } else if (l->type == NodeType::LIST && r->type == NodeType::INT) {
            auto dummy = make_shared<Node>(0, NodeType::LIST);
            dummy->children.emplace_back(make_shared<Node>(r->value));
            return isOrdered(l, dummy.get());
        } else if (l->type == NodeType::INT && l->type == r->type) {
            if (l->value == r->value) {
                return 0;
            }

            return (l->value < r->value) ? -1 : 1;
        } else if (l->type == NodeType::LIST && l->type == r->type) {
            int i = 0;
            while (i < l->children.size() && i < r->children.size()) {
                int childResult = isOrdered(l->children[i].get(), r->children[i].get());
                if (childResult != 0) {
                    return childResult;
                }
                ++i;
            }
            if (l->children.size() == r->children.size()) {
                return 0;
            }

            return (l->children.size() < r->children.size()) ? -1 : 1;
        }

        throw std::logic_error("Could not map types to case.");
    };

    return isOrdered(&l, &r) == -1;
}

void solve_part1() {
    string leftLine;
    int pairIdx = 1, ans = 0;
    while (getline(cin, leftLine)) {
        string rightLine; getline(cin, rightLine);

        Node left(0, NodeType::LIST), right(0, NodeType::LIST);
        Tokenizer leftTokens(leftLine), rightTokens(rightLine);

        parseLine(&left, leftTokens);
        parseLine(&right, rightTokens);

        getline(cin, leftLine);

        // cout << left << endl;
        // cout << right << endl;

        function<int(Node*, Node*)> isOrdered = [&](Node* l, Node* r) -> int {
            if (l->type == NodeType::INT && r->type == NodeType::LIST) {
                auto dummy = make_shared<Node>(0, NodeType::LIST);
                dummy->children.emplace_back(make_shared<Node>(l->value));
                return isOrdered(dummy.get(), r);
            } else if (l->type == NodeType::LIST && r->type == NodeType::INT) {
                auto dummy = make_shared<Node>(0, NodeType::LIST);
                dummy->children.emplace_back(make_shared<Node>(r->value));
                return isOrdered(l, dummy.get());
            } else if (l->type == NodeType::INT && l->type == r->type) {
                if (l->value == r->value) {
                    return 0;
                }

                return (l->value < r->value) ? -1 : 1;
            } else if (l->type == NodeType::LIST && l->type == r->type) {
                int i = 0;
                while (i < l->children.size() && i < r->children.size()) {
                    int childResult = isOrdered(l->children[i].get(), r->children[i].get());
                    if (childResult != 0) {
                        return childResult;
                    }
                    ++i;
                }
                if (l->children.size() == r->children.size()) {
                    return 0;
                }

                return (l->children.size() < r->children.size()) ? -1 : 1;
            }

            throw std::logic_error("Could not map types to case.");
        };

        int order = isOrdered(&left, &right) ;
        cout << order << endl;

        if (order == -1) ans += pairIdx;

        ++pairIdx;
    }

    cout << ans << endl;
}

void solve_part2() {
    vector<Node> all_nodes;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        Tokenizer tok(line);
        Node curNode(0, NodeType::LIST);
        parseLine(&curNode, tok);
        all_nodes.emplace_back(curNode);
    }

    sort(begin(all_nodes), end(all_nodes));

    for (auto node : all_nodes)
        cout << node << endl;

    auto div0_idx = find_if(begin(all_nodes), end(all_nodes), [](const Node& node) {
        if (node.children.size() == 1) {
            auto childNode = node.children[0].get();
            return childNode->children.size() == 1 && (childNode->children[0].get())->value == 2;
        }
        return false;
    }) - begin(all_nodes) + 1;
    auto div1_idx = find_if(begin(all_nodes), end(all_nodes), [](const Node& node) {
        if (node.children.size() == 1) {
            auto childNode = node.children[0].get();
            return childNode->children.size() == 1 && (childNode->children[0].get())->value == 6;
        }
        return false;
    }) - begin(all_nodes) + 1;

    cout << div0_idx << endl;
    cout << div1_idx << endl;


    cout << div0_idx * div1_idx << endl;
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
    // solve_part1();
    solve_part2();
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}