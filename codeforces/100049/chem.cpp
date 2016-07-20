#include <iostream>
bool is_vowel(char ch) {
    switch (ch) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
        break;
    }
    return false;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::string ciphertext;
    while (std::cin >> ciphertext) {
        std::string ans;
        ans.reserve(ciphertext.length());
        size_t i;
        for (i = 0; i < ciphertext.length(); i++) {
            if (is_vowel(ciphertext[i])) {
                ans.push_back(ciphertext[i]);
                i += 2;
            } else {
                ans.push_back(ciphertext[i]);
            }
        }
        std::cout << ans << std::endl;
    }
}
