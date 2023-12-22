class Solution {
public:
    int maxScore(string& s) {
        int ans = 0;
        int zeros = 0;
        int ones = 0;
        for (char c : s) if (c == '1') ++ones;
        for (int i=0; i<s.size()-1; ++i){
            if (s[i] == '0') ++zeros;
            else --ones;
            ans = max(ans,zeros+ones);
        }
        return ans;
    }
};
