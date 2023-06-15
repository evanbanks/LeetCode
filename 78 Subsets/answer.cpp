class Solution {
    std::vector<int> curr;
    std::vector<std::vector<int>> sol;

    void dfs(const int k, const std::vector<int>& nums){
        if (k == nums.size()){
            sol.push_back(curr);
        } else {
            curr.push_back(nums[k]);
            dfs(k+1,nums);
            curr.pop_back();
            dfs(k+1,nums);
        }
    }
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        dfs(0,nums);
        return sol;
    }
};
