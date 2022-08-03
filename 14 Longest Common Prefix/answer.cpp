#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        std::string prefix;
        size_t min_length = std::numeric_limits<int>::max();
        for(const auto& s : strs){
            min_length = std::min(min_length, s.size());
        }
        for (int i=0; i<min_length; ++i){
            bool equal = true;
            char c = strs[0][i];
            for (int j=1; j<strs.size(); ++j){
                if (strs[j][i] != strs[0][i]) equal = false;
            }
            if (equal){
                prefix += c;
            } else {
                return prefix;
            }
        }
        return prefix.size() ? prefix : "";
    }
};