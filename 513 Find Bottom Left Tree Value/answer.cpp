class Solution {
    std::pair<int,int> left = {-1,-1};

    void dfs(TreeNode* const curr, const int depth){
        if (!curr) return;
        if (depth > left.second) left = {curr->val,depth};
        dfs(curr->left,depth+1);
        dfs(curr->right,depth+1);

    }
public:
    int findBottomLeftValue(TreeNode* const root) {
        dfs(root,0);
        return left.first;
    }
};
