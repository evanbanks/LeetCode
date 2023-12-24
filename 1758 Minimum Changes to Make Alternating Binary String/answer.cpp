class Solution {
public:
    int minOperations(string& s) {
        int a = 0;
        for (int i=0; i<s.size(); ++i){
            if (i%2 && s[i] == '1') ++a;
            else if (i%2 == 0 && s[i] == '0') ++a;
        }
        return min(a,(int)s.size()-a);
    }
};
