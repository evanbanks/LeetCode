class Solution {
public:
    int longestContinuousSubstring(const std::string& s) {
        int ans = 1, curr = 1;
        for (int i=1; i<s.size(); ++i){
            if (s[i] == s[i-1]+1){
                ans = std::max(ans,++curr);
            } else {
                curr = 1;
            }
        }
        return ans;   
    }
};
