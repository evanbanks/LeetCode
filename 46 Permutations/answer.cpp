class Solution {
    std::vector<int> curr;
    std::vector<std::vector<int>> sol;
    std::unordered_set<int> visited;

    void dfs(const std::vector<int>& nums){
        if (curr.size() == nums.size()){
            sol.push_back(curr);
        } else {
            for (const int n : nums){
                if (visited.find(n) == visited.end()){
                    visited.insert(n);
                    curr.push_back(n);
                    dfs(nums);
                    curr.pop_back();
                    visited.erase(n);
                }
            }
        }
    }

public:
    std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
        dfs(nums);
        return sol;
    }
};
