class Solution {
    std::vector<int> path;
    std::vector<std::string> sol;

    void dfs(TreeNode* const root){
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right){
            std::string s;
            for (size_t i=0; i<path.size()-1; ++i){
                s += std::to_string(path[i]) + "->";
            }
            s += std::to_string(path[path.size()-1]);
            sol.push_back(s);
        } else {
            dfs(root->left);
            dfs(root->right);
        }
        path.pop_back();
    }
public:
    std::vector<std::string> binaryTreePaths(TreeNode* const root) {
        dfs(root);
        return sol;
    }
};
