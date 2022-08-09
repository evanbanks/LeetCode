#include <string>

class Solution {
public:
    bool backspaceCompare(std::string& s, std::string& t) {
        int new_size=0;
        for (size_t i=0; i<s.size(); ++i){
            if (s[i] == '#'){
                new_size = std::max(--new_size,0);
            } else {
                s[new_size++] = s[i];
            }
        }
        s = s.substr(0,new_size);
        new_size=0;
        for (size_t i=0; i<t.size(); ++i){
            if (t[i] == '#'){
                new_size = std::max(--new_size,0);
            } else {
                t[new_size++] = t[i];
            }
        }
        t = t.substr(0,new_size);
        return s == t;
    }
};