#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(const std::string& s) {
        int longest = 0, length = 0;
        std::unordered_map<char,int> freq;
        for (int ws=0, we=0; we<s.size(); ++we){
            ++length;
            ++freq[s[we]];
            while (freq.size() > 2){
                --freq[s[ws]];
                if (!freq[s[ws]]) freq.erase(s[ws]);
                ++ws;
                --length;
            }
            longest = std::max(longest,length);
        }
        return longest;
    }
};