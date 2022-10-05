#include <vector>
#include <string>

class Solution {
public:
  std::vector<std::string> fizzBuzz(const int n) {
    std::vector<std::string> ans(n);
    for (int i=1; i<=n; ++i){
      if (!(i%3+i%5)){
        ans[i-1] = "FizzBuzz";
      } else if (!(i%3)){
        ans[i-1] = "Fizz";
      } else if (!(i%5)){
        ans[i-1] = "Buzz";
      } else {
        ans[i-1] = std::to_string(i);
      }
    }
    return ans;
  }
};