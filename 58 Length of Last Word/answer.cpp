#include <string>

class Solution {
public:
    int lengthOfLastWord(const std::string& s) {
        int length = 0;
        bool word_started = false;
        for (int i=s.size()-1; i >= 0; --i){
            if (s[i] != ' '){
                word_started = ++length;
            } else if (word_started) break;
        }
        return length;
    }
};