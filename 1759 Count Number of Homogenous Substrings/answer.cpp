using ll = long long;

class Solution {
public:
    int countHomogenous(const string& s) {
        const ll mod = 1e9+7;
        ll ans = 1;
        ll length = 1;
        for (int i=1; i<s.size(); ++i){
            if (s[i] == s[i-1]) ++length;
            else length = 1;
            ans += length;
        }
        return ans % mod;
    }
};
