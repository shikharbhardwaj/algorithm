#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int MAX_N = atoi(argv[1]);

    int n = rnd.next(1, MAX_N), m = rnd.next(1, MAX_N), d = rnd.next(1, 20);
    int k = rnd.next(1, n);

    cout << n << " " << m << " " << d << " " << k << endl;

    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    shuffle(begin(letters), end(letters));

    cout << letters.substr(0, d) << endl;

    string x = "[A-Z]{" + to_string(m) + "}";
    pattern p(x);

    for (int i = 0; i < n; ++i) {
        cout << p.next(rnd) << endl;
    }
}
