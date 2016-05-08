#include <iostream>
#include <algorithm>
int main(){
    int T;
    std::string in;
    std::cin>>T;
    while(T--){
        std::cin>>in;
        for(int i = in.size()-1; i >= 0; i--){
            if(in[i] == '0'){
                in.pop_back();
            }
            else{
                break;
            }
        }
        std::reverse(in.begin(), in.end());
        std::cout<<in<<std::endl;
    }
}
