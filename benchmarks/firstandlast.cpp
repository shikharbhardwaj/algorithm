#include <iostream>
int main(){
    std::string input;
    int T;
    std::cin>>T;
    while(T--){
        std::cin>>input;
        if(input.size() > 1){
            std::cout<<(input[0]+input[input.size()-1]-2*'0');
        }
        else{
            std::cout<<input;
        }
        std::cout<<"\n";
    }
}
