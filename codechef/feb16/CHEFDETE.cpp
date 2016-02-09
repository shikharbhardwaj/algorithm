#include <iostream>
bool occured[100001];
int main(){
    std::ios_base::sync_with_stdio(false);
    int N, temp;
    std::cin>>N;
    for(int i = 1; i <= N; i++){
        occured[i] = false;
    }
    for(int i = 1; i <= N; i++){
        std::cin >> temp;
        if(temp == 0){
            //This is the Don
            occured[i] = true;
        }
        occured[temp] = true;
    }
    for(int i = 1; i <= N; i++){
        if(!occured[i]){
            std::cout<<i<<" ";
        }
    }
    std::cout<<"\n";
}

