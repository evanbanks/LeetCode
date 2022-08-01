#include <string>

class Solution {
public:
    bool isIsomorphic(const std::string& s, const std::string& t) {
        char s_indices[128] {0};
        char t_indices[128] {0}; 
        for (size_t i=0; i<s.size(); ++i){
            if (s_indices[s[i]] != t_indices[t[i]]) return false;
            s_indices[s[i]] = i + 1;
            t_indices[t[i]] = i + 1;
        }
        return true;
    }
};