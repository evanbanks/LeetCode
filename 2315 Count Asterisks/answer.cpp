#include <string>

class Solution {
public:
    int countAsterisks(const std::string& str) {
        bool inbetween = false;
        int count = 0;
        for (const auto& s : str){
            if (s == '|'){
                inbetween = !inbetween;
            } else if (s == '*' && !inbetween){
                ++count;
            }
        }
        return count;
    }
};