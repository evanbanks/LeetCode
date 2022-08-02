#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findAnagrams(const std::string& str, const std::string& pattern) {
        std::vector<int> resultIndices;
        int matched = 0;
        std::unordered_map<char,int> freq;
        for (const auto& p : pattern){
          if (++freq[p] == 1) ++matched;
        } 
        for (int ws=0, we=0; we<str.size(); ++we){
          --freq[str[we]];
          if (!freq[str[we]]) --matched;
          if (we > pattern.size()-1){
            if (++freq[str[ws++]] == 1) ++matched;
          }
          if (!matched) resultIndices.push_back(ws);
        }
        return resultIndices;
    }
};