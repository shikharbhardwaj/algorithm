//An implemenation of the naive string matching algorithm
#include <iostream>
void naive_string_matcher(const std::string &S, const std::string &P){
  if(S.length() < P.length()){
    return;
  }
  if(S.empty() || P.empty()){
    return;
  }
  size_t cur_index, j;
  for(size_t i = 0; i < S.length(); i++){
    cur_index = 0;
    j = i;
    while(P[cur_index] == S[i] && cur_index < P.length()){
      cur_index++;
      i++;
    }
    if(cur_index == P.length()){
      std::cout<<"\nOccurance found at : "<<j;
    }
    i = j;
  }
}
int main(){
    naive_string_matcher("AABAACAADAABAAABAA","AABA");
    return 0;
}
