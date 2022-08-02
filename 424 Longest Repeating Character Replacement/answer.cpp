#include <string>
#include <unordered_map>

class Solution {
public:
    int characterReplacement(const std::string& str, const int k) {
        int max_length = 0, length = 0, highest = 0;
        std::unordered_map<char,int> freq;
        for (int ws=0, we=0; we<str.size(); ++we){
            ++freq[str[we]];
            ++length;
            highest = std::max(highest, freq[str[we]]);
            if (length - highest > k){
                --freq[str[ws]];
                ++ws;
                --length;
            }
            max_length = std::max(max_length, length);
        }
        return max_length;
    }
};