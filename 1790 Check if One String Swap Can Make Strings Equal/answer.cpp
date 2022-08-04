#include <vector>
#include <string>

class Solution {
public:
    bool areAlmostEqual(const std::string& s1, const std::string& s2) {
        std::vector<int> diff_indices;
        for (size_t i=0; i<s1.size(); ++i){
            if (s1[i] != s2[i]){
              diff_indices.push_back(i);
            } 
        }
        if (!diff_indices.size()) return true;
        if (diff_indices.size() == 2){
            return s1[diff_indices[0]] == s2[diff_indices[1]] && s1[diff_indices[1]] == s2[diff_indices[0]];
        }
        return false;
    }
};