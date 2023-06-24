class Solution {
    std::vector<int> curr;
    std::vector<std::vector<int>> sol;

    void dfs(TreeNode* const root, const int targetSum){
        if (!root) return;
        curr.push_back(root->val);
        if (targetSum == root->val && !root->left && !root->right) sol.push_back(curr);
        else {
            dfs(root->left,targetSum-root->val);
            dfs(root->right,targetSum-root->val);
        }
        curr.pop_back();
    }
public:
    std::vector<std::vector<int>> pathSum(TreeNode* const root, const int targetSum) {
        dfs(root,targetSum);
        return sol;
    }
};
