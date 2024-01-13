class Solution {
public:
    int minSteps(string& s, string& t) {
        vector<int> v(26);
        for (int i=0; i<s.size(); ++i){
            ++v[s[i]-97];
            --v[t[i]-97];
        }
        int ans = 0;
        for (int i=0; i<v.size(); ++i){
            ans += abs(v[i]);
        }
        return ans / 2;
    }
};
