#include <iostream>
#include <vector>
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
int main(){
    int n1, n2, m1, m2;
    std::cout<<"\n n1, m1, n2, m2 : ";
    std::cin>>n1>>m1>>n2>>m2;
    if(m1 != n2){
        return -1;
    }
    else{
        //We are multiplying matrices
        vvi first(n1);
        vvi second(n2);
        vvi result(n1);
        for( auto &elem : first ){
            elem = vi(m1);
        }
        for( auto &elem : second ){
            elem = vi(m2);
        }
        for( auto &elem : result){
            elem = vi(m2, 0);
        }
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < m1; j++){
                std::cin>>first[i][j];
            }
        }
        for(int i = 0; i < n2; i++){
            for(int j = 0; j < m2; j++){
                std::cin>>second[i][j];
            }
        }
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < m2; j++){
                for(int k = 0; k < m1; k++){
                    result[i][j] += (first[i][k] * second[k][j]);
                }
            }
        }
        for( const auto &row : result ){
            for( auto elem : row ){
                std::cout<<" : "<<elem;
            }
            std::cout<<"\n";
        }
    }
}
