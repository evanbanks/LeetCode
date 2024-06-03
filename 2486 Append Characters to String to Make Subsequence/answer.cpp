class Solution {
public:
    int appendCharacters(string& s, string& t) {
        int n = 0;
        for (char c : s){
            if (c == t[n]) ++n;
        }
        return t.size()-n;
    }
};
