class Solution {
    int reverse(int a){
        int b = 0;
        while (a){
            b *= 10;
            b += a % 10;
            a /= 10;
        }
        return b;
    }
public:
    int countNicePairs(vector<int>& nums) {
        const int mod = 1e9+7;
        long long ans = 0;
        unordered_map<int,int> freq;
        for (int i : nums){
            i -= reverse(i);
            ans += freq[i]++;
        }
        return ans % mod;
    }
};
