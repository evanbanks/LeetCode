#include <algorithm>

class Solution {
public:
    bool isPalindrome(const int x) {
        std::string s_r = std::to_string(x);
        std::reverse(s_r.begin(), s_r.end());
        return s_r == std::to_string(x);
    }
};