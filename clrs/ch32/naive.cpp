#include <iostream>
#include <typeinfo>
int find_occurences(const std::string &T, const std::string& P){
    int occurences = 0;
    unsigned j = 0, cur_index;
    for(unsigned i = 0; i < T.length(); i++, j=0){
        cur_index = i;
        if(T[i] == P[j]){
            while(T[i] == P[j] && j < P.length() && i < T.length()){
                j++;
                i++;
            }
            if(j == P.length()){
                occurences++;
            }
        }
        i = cur_index;
    }
    return occurences;
}
void naive_string_matcher(std::string T, std::string P){
    auto n = T.length();
    auto m = P.length();
    unsigned s, i, cur_index;
    for(s = 0; s < n - m; s++){
        cur_index = s;
        for(i = 0; i < m; i++){
            if(T[s+i] != P[i]){
                break;
            }
        }
        if(i == m){
            std::cout<<"The string occurs with the shift : "<<s<<"\n";
        }
        s = cur_index;
    }
}
int main(){
    std::cout<<find_occurences("ststaststast","ststast")<<"\n";
    return 0;
}
