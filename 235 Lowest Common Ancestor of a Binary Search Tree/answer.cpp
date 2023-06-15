class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* const p, TreeNode* const q) {
        while (true){
            if (p->val > root->val && q->val > root->val){
                root = root->right;
            } else if (p->val < root->val && q->val < root->val){
                root = root->left;
            } else {
                return root;
            }
        }
    }
};
