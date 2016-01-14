#include <iostream>
std::string::const_iterator naive_search(const std::string &text, const std::string &pattern){
  for(auto it = text.begin(); it != text.end(); it++){
    auto pt = pattern.begin();
    auto needle = it;
    for(; pt != pattern.end() && needle != text.end(); pt++){
      if(*needle == *pt){
        needle++;
      }
      else{
        break;
      }
    }
    if(pt == pattern.end() ){
      return it;
    }
  }
  return text.end();
}
std::string::const_iterator KMP_search(const std::string& text, const std::string &pattern){

  return text.end();
}
int main(){
  std::cout<<"\nMatching mathematics with mat";
  std::string text = "mathematics";
  std::string::const_iterator pos;
  if((pos = naive_search(text, "mati")) != text.end()){
    std::cout<<"\nFound at index : "<<pos - text.begin();
  }
}

