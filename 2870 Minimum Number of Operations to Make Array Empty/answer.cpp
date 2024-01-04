class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int i : nums) ++freq[i];
        int ans = 0;
        for (auto& [f,s] : freq){
            if (s == 1) return -1;
            ans += ceil(s/3.0);
        }
        return ans;
    }
};
