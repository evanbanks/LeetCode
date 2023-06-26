class Solution {
    std::vector<int> sol;
public:
    std::vector<int> inorderTraversal(TreeNode* const root) {
        if (!root) return {};
        inorderTraversal(root->left);
        sol.push_back(root->val);
        inorderTraversal(root->right);
        return sol;
    }
};
