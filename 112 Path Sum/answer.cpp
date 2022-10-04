class Solution {
public:
    bool hasPathSum(TreeNode* const root, const int targetSum) const {
        if (!root){
          return false;
        }
        int rest = targetSum-root->val;
        if (!rest && !root->left && !root->right){
          return true;
        }
        return hasPathSum(root->right, rest) || hasPathSum(root->left, rest);
    }
};