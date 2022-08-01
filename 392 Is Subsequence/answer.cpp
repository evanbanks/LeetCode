#include <string>

class Solution {
public:
    bool isSubsequence(const std::string& s, const std::string& t) {
        size_t j = 0;
        for (size_t i=0; i<t.size() && j<s.size(); ++i){
            if (s[j] == t[i]) ++j;
        }
        return j == s.size();
    }
};