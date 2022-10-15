class Solution {
public:
  int maxDepth(const TreeNode const * root) const {
    if (!root) return 0;
    return 1 + std::max(maxDepth(root->left),maxDepth(root->right));
  }
};
