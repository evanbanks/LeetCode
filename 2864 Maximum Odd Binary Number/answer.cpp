class Solution {
public:
    string maximumOddBinaryNumber(string& s) {
        int ones = 0;
        for (char c : s) if (c == '1') ++ones;
        int zeros = s.size()-ones;
        string ans;
        while (--ones) ans += '1';
        while (zeros--) ans += '0';
        ans += '1';
        return ans;
    }
};
