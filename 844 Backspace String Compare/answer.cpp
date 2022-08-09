#include <string>

int get_next_char(const std::string& s, const int start_index){
    int index = start_index;
    int b_count = 0;
    while (index >= 0){
        if (s[index] == '#') ++b_count;
        else if (b_count > 0) --b_count;
        else break;
        --index;
    }
    return index;
}



class Solution {
public:
    bool backspaceCompare(const std::string& s, const std::string& t) {
        int s_index = s.size()-1, t_index = t.size()-1;
        while (s_index >=0 || t_index >=0){
            int si = get_next_char(s,s_index);
            int ti = get_next_char(t,t_index);
            if (si < 0 && ti < 0) return true;
            if (si < 0 || ti < 0) return false;
            if (s[si] != t[ti]) return false;
            s_index = si-1;
            t_index = ti-1;
        }
        return true;
    }
};