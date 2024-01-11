class Solution {
    void solve(TreeNode* root, int ma, int mi, int& ans){
        if (!root) return;
        ans = max({ans,abs(root->val-ma),abs(root->val-mi)});
        solve(root->left,max(ma,root->val),min(mi,root->val),ans);
        solve(root->right,max(ma,root->val),min(mi,root->val),ans);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        solve(root,root->val,root->val,ans);
        return ans;
    }
};
