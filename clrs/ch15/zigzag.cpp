#include <vector>
#include <algorithm>
class ZigZag{
  private:
  public:
    ZigZag() = default;
    int longestZigZag(std::vector<int> sequence){
      std::vector<int> state1(sequence.size(), 1);
      std::vector<int> state2(sequence.size(), 1);
      for(unsigned i = 1; i < sequence.size(); i++){
        for(int j = i - 1; j >= 0 ; j--){
          if(sequence[i] - sequence[j] > 0 && state2[i] < state1[j] + 1){
            state2[i] = state1[j] + 1;
          }
          else if(sequence[j] - sequence[i] > 0 && state1[i] < state2[j] + 1){
            state1[i] = state2[j] + 1;
          }
        }
      }
      return std::max(*std::max_element(state1.begin(), state1.end()), *std::max_element(state2.begin(), state2.end()));
    }
};

