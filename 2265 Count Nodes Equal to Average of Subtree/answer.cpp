pair<int,int> solve(TreeNode* const u, int& ans){
    if (!u) return {0,0};
    pair<int,int> p1 = solve(u->left,ans);
    pair<int,int> p2 = solve(u->right,ans);
    p1.first += p2.first + u->val;
    p1.second += p2.second + 1;
    int avg = p1.first / p1.second;
    if (u->val == avg) ++ans;
    return p1;

}

class Solution {
public:
    int averageOfSubtree(TreeNode* const root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};
