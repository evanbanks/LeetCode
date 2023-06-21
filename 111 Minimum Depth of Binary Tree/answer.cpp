class Solution {
  int dfs(TreeNode* const root){
    if (!root) return 0;
    if (!root->left){
      return 1 + dfs(root->right);
    } else if (!root->right){
      return 1 + dfs(root->left);
    }
    return std::min(1 + dfs(root->left), 1 + dfs(root->right));
  }
public:
    int minDepth(TreeNode* const root) {
      return dfs(root);
    }
};
