#include <string>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(const std::string& str, const std::string& pattern) {
        int matched = 0;
        int min_length = str.size()+1;
        int min_start = str.size();
        std::unordered_map<char, int> freq;
        for (const auto& p : pattern){
            if (++freq[p] == 1) ++matched;
        } 
        for (int ws=0, we=0; we<str.size(); ++we){
            if (!--freq[str[we]]) --matched;
            while (!matched){
                if (min_length > we-ws+1){
                    min_length = we-ws+1;
                    min_start = ws;
                    if (min_length == pattern.size()) return str.substr(min_start,min_length);
                }
                if (++freq[str[ws++]] == 1) ++matched;
            }
        }
        return str.substr(min_start,min_length);
    }
};