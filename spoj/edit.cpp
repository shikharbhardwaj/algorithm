// Solution to SPOJ : Edit distance
#include <iostream>
#include <array>
#include <algorithm>
enum cost_table{ rep = 1, del = 1, ins = 1 };
std::string A, B;
std::array<std::array<int, 2048>, 2048> costs; //Memo table
int cost_rep(char A, char B){
    if( A == B ){
        //If the same char, no cost
        return 0;
    }
    return cost_table::rep;
}
int min_cost(size_t i, size_t j){
    //Limit out of boundary calls
    if( costs[i][j] != -1){
        return costs[i][j];
    }
    if( i == A.size()-1 || j == B.size() - 1 ){
        //Handle walls here
        if( i == A.size() - 1 && j == B.size() - 1 ){
            costs[i][j] = cost_rep(A[i], B[j]); //We are done
        }
        else if( i == A.size() - 1 ){
            costs[i][j] = min_cost(i, j+1) + cost_table::del; //Only delete
        }
        else if( j == B.size() - 1 ){
            costs[i][j] = min_cost(i+1, j) + cost_table::ins; //Only insert
        }
    }
    else{
        costs[i][j] = std::min(min_cost(i+1, j+1) + cost_rep(A[i], B[j]),
                      std::min(min_cost(i+1, j) + cost_table::ins,
                               min_cost(i, j+1) + cost_table::del));
    }
    return costs[i][j];
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    std::cin>>T;
    while(T--) {
        std::cin>>A>>B;
        for( auto &elem : costs ){ elem.fill(-1); }
        std::cout<<min_cost(0,0)<<"\n";
    }
}

