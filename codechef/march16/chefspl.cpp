#include <iostream>
#include <algorithm>
#include <array>
bool is_special( const std::string &in ){
    if( in.size() <= 1 ){
        //Empty or single char strings are not special
        return false;
    }
    //Freq table optimization
    //Does not make a large difference
    std::array<int, 26> freq;
    std::generate(freq.begin(), freq.end(), []{return 0;});
    int odds = 0;
    for( auto elem : in ){
        freq[elem - 'a']++;
    }
    for( auto elem : freq ){
        if(elem%2 != 0){
            odds++;
        }
        if( odds > 1 ){
            return false;
        }
    }
    if( in.size()%2 == 0 ){
        if( odds == 1 ){
            return false;
        }
        auto pivot = in.begin() + in.size()/2;
        if(std::equal(in.begin(), pivot, pivot)){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        //We have 3 cases : 
        //
        //Skipped char in 1st half, skipped char in second half
        //or the skipped char is the middle one
        //Eliminating the third case
        auto mid = in.begin() + in.size()/2;
        if( std::equal(in.begin(), mid, mid+1) ){
            return true;
        }
        bool skipped = false;
        size_t right_id, left_id, filled = 0;
        //If skipped char in the first half, the mid char belongs to 
        //the first string
        left_id = 0;
        right_id = in.size()/2 + 1;
        while( filled < in.size()/2){
            if( in[right_id] != in[left_id] ){
                if( skipped ){
                    break;
                }
                if( in[left_id+1] == in[right_id] ){
                    left_id++;
                    skipped = true;
                }
                else{
                    break;
                }
            }
            filled++; right_id++; left_id++;
            if( left_id == right_id && filled < in.size()/2){
                break;
            }
        }
        if( filled == in.size()/2 ){
            return true;
        }
        skipped = false;
        filled = 0;
        left_id = 0;
        right_id = in.size()/2;
        while( filled < in.size()/2){
            if( in[right_id] != in[left_id] ){
                if( skipped ){
                    return false;
                }
                if( in[right_id+1] == in[left_id] ){
                    right_id++;
                    skipped = true;
                }
                else{
                    return false;
                }
            }
            filled++; right_id++; left_id++;
            if( left_id == right_id && filled < in.size()/2){
                return false;
            }
        }
        if( filled == in.size()/2 ){
            return true;
        }
    } 
    return false;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::string name;
    int D;
    std::cin>>D;
    while( D-- ){
        std::cin>>name;
        if ( is_special(name) ){
            std::cout<<"YES";
        }
        else{
            std::cout<<"NO";
        }
        std::cout<<"\n";
    }
}

