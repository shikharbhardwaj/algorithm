#include <iostream>
#include <algorithm>
bool is_similar(const std::string &first, const std::string &second){
    //Naive check for two similar strings
    //has nothing to do with the final solution so forget about this
    if( first.length() != second.length() ){
        return false;
    }
    if( first == second ){
        return true;
    }
    auto res = first;
    for( size_t i = 0; i < first.length() - 1; i++ ){
        for( size_t j = i + 1; j < first.length(); j++ ){
            std::swap(res[i], res[j]);
            if( res == second ){
                return true;
            }
            res = first;
        }
    }
    return false;
}
int count_not_similar(const std::string &in){
    auto val = in;
    std::sort(in.begin(), in.end());
    //This is shitty,
    //basically question of PnC 
    //May need Fermat's little theorem when you have the final formula
    return 0;
}
int main(){
    //std::ios_base::sync_with_stdio(false);
    //int T;
    //std::string in;
    //std::cin>>T;
    //while(T--){
        //std::cin>>in;
    //}
    std::cout<<std::boolalpha<<is_similar("abcd", "abcd");
}
