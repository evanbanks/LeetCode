class Solution {
public:
    bool isSameTree(TreeNode* const a, TreeNode* const b) {
        if ((!a && b) || (a && !b)){
            return false;
        }
        if (!a && !b) return true;
        if (a->val != b->val) return false;
        return (isSameTree(a->left,b->left) && isSameTree(a->right,b->right));
    }
};