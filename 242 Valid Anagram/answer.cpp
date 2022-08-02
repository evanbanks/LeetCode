#include <string>

class Solution {
public:
    bool isAnagram(const std::string& s, const std::string& t) {
        if (s.size() != t.size()){
            return false;
        }
        short freq[123] {};
        for (int i=0; i<s.size(); ++i){
            ++freq[s[i]];
            --freq[t[i]];
        }
        for (int i=0; i<s.size(); ++i){
            if (freq[s[i]]){
                return false;
            }
        }
        return true;
    }
};