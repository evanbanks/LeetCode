#include <string>

class Solution {
public:
    char repeatedCharacter(const std::string& s) {
        char freq[26] {};
        for (const auto& c : s){
            if (freq[c-'a']) return c;
            ++freq[c-'a'];
        }
        return '\0';
    }
};