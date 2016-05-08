#include <iostream>
#include <string>
using namespace std;
bool is_nines(const std::string &num){
    for(auto elem : num){
        if(elem != '9'){
            return false;
        }
    }
    return true;
}
int main(){
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);
    int T;
    std::string num;
    scanf("%d", &T);
    while(T--){
        cin>>num;
        if(is_nines(num)){
            cout<<"1";
            for(int i = 0; i < num.size() - 1; i++){
                cout<<"0";
            }
            cout<<"1\n";
        }
    }
}
