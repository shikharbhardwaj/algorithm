#include <iostream>
#include <vector>
std::vector<int> height;
std::vector<int> bloom;
std::vector<int> wilt;
bool blocks[50][50];
//Each index i, j indicates whether i blocks j 
void fillBlock(unsigned i){
  if(i >= height.size()){
    return;
  }
  for(unsigned j = 0; j < height.size(); j++){
    if(i == j){
      continue;
    }
    else{
      if(!(bloom[j] > wilt[i] || bloom[i] > wilt[j])){
        if(height[i] > height[j]){
          blocks[i][j] = 1;
          blocks[j][i] = 0;
        }
      }
      else{
        blocks[i][j] = blocks[j][i] = 0;
      }
    }
  }
  fillBlock(i+1);
}
int main(){
  height = {5,4,3,2,1};
  bloom = {1,5,10,15,20};
  wilt = {5,10,15,20,25};
  fillBlock(0);
  for(unsigned i = 0; i < height.size(); i++){
    for(unsigned j = 0; j < height.size(); j++){
      std::cout<<" : "<<blocks[i][j];
    }
    std::cout<<"\n";
  }
  std::cout<<"\n";
  for(auto elem : height){
    std::cout<<" : "<<elem;
  }
  std::cout<<"\n";
}
