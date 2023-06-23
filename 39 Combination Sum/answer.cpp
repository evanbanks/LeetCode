class Solution {
    std::vector<int> curr;
    std::vector<std::vector<int>> sol;

    void dfs(const int k, int target, const std::vector<int>& candidates){
        if (target <= 0){
            if (!target) sol.push_back(curr);
        } else {
            for (size_t i=k; i<candidates.size(); ++i){
                curr.push_back(candidates[i]);
                dfs(i,target-candidates[i],candidates);
                curr.pop_back();
            }
        }
    }
public:
    std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, const int target) {
        dfs(0,target,candidates);
        return sol;
    }
};
