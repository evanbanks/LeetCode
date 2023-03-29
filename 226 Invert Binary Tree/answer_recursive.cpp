class Solution {
public:
    TreeNode* invertTree(TreeNode* const root) const {
        if (root){
            std::swap(root->left,root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};
