#include <string>
#include <unordered_map>

class Solution {
public:
    bool checkInclusion(const std::string& pattern, const std::string& str) {
    int matched = 0;
    std::unordered_map<char,int> freq;
    for (const auto& p : pattern){
      if (++freq[p] == 1) ++matched;
    } 
    for (int ws=0, we=0; we<str.size(); ++we){
      if (!--freq[str[we]]) --matched;
      if (we > pattern.size()-1){
        if (++freq[str[ws++]] == 1) ++matched;
      }
      if (!matched) return true;
    }
    return false;
  }
};

