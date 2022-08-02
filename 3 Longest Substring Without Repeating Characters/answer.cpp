#include <string>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(const std::string& str) {
        int max_length = 0;
        int length = 0;
        std::unordered_set<char> contained;
        for(int ws=0, we=0; we<str.size(); ++we){
            while (contained.count(str[we])){
                contained.erase(str[ws++]);
                --length;
            }
            contained.insert(str[we]);
            length++;
            max_length = std::max(length, max_length);
        }
        return max_length;
    }
};