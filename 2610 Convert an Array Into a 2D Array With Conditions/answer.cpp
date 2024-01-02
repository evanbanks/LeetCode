class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq(nums.size()+1);
        vector<vector<int>> v;
        for (int i : nums){
            if (freq[i] == v.size()) v.push_back({});
            v[freq[i]].push_back(i);
            ++freq[i];
        }
        return v;
    }
};
