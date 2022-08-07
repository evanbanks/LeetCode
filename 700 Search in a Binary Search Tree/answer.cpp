class Solution {
public:
    TreeNode* searchBST(TreeNode* root, const int val) {
        while (root != nullptr){
            if (root->val == val) return root;
            if (root->val > val){
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return nullptr;
    }
};