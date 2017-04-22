#include <iostream>
#include <random>
using namespace std;
random_device rd;
mt19937 gen(rd());

int main(int argc, char *argv[]){
    int T = atoi(argv[1]);
    int N = atoi(argv[2]);
    int Q = atoi(argv[3]);
    uniform_int_distribution<int> dist(0, 100);
    uniform_int_distribution<int> range(1, N);
    uniform_int_distribution<int> kdist(1, sqrt(N));
    cout << T << endl;
    while(T--){
        cout << N << " " << Q << endl;
        for(int i = 0; i < N; ++i){
            cout << dist(gen) << " ";
        }
        cout << endl;
        for(int i = 0; i < Q; ++i){
            int l = range(gen);
            int r = uniform_int_distribution<int>(l, N)(gen);
            int k = kdist(gen);
            cout << l << " " << r <<  " " << k << endl;
        }
    }
}
