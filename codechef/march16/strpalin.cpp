#include <iostream>
#include <array>
#include <algorithm>
std::array<int, 26> freq_table;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::string a, b;
    int T;
    bool flag;
    std::cin>>T;
    while( T-- ){
        flag = false;
        std::generate(freq_table.begin(), freq_table.end(), []{return 0;});
        std::cin>>a>>b;
        for( auto elem : a ){
            freq_table[elem-'a']++;
        }
        for( auto elem : b ){
            if( freq_table[elem - 'a'] != 0){
                flag = true;
                break;
            }
        }
        if( flag ){
            std::cout<<"Yes";
        }
        else{
            std::cout<<"No";
        }
        std::cout<<"\n";
    }
}

