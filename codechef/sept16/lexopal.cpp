#include <iostream>
bool is_pal(const std::string &str) {
    for (size_t i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - i - 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::string str;
    int T;
    std::cin >> T;
    while (T--) {
        std::cin >> str;
        if (str.length() % 2) {
            // This is odd length
            if (str[str.length() / 2] == '.') {
                str[str.length() / 2] = 'a';
            }
        }
        for (size_t i = 0; i < str.length() / 2; i++) {
            auto &l_char = str[i];
            auto &r_char = str[str.length() - i - 1];
            if (l_char == '.' && r_char != '.')
                l_char = r_char;
            else if (l_char != '.' && r_char == '.')
                r_char = l_char;
            else if (l_char == '.' && r_char == '.')
                l_char = r_char = 'a';
        }
        if (is_pal(str))
            std::cout << str << "\n";
        else
            std::cout << "-1\n";
    }
}
