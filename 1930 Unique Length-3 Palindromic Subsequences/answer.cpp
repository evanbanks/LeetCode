class Solution {
public:
    int countPalindromicSubsequence(string& s) {
        vector<pair<int,int>> fs(26,{-1,-1});
        for (int i=0; i<s.size(); ++i){
            s[i] -= 97;
            if (fs[s[i]].first != -1){
                fs[s[i]].second = i;
            } else {
                fs[s[i]].first = i;
            }
        }
        int ans = 0;
        for (int i=0; i<26; ++i){
            if (fs[i].second == -1) continue;
            unordered_set<char> distinct;
            for (int j=fs[i].first+1; j<fs[i].second; ++j) distinct.insert(s[j]);
            ans += distinct.size();
        }
        return ans;
    }
};
