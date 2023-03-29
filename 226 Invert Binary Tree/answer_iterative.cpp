class Solution {
public:
    TreeNode* invertTree(TreeNode* const root) const {
        std::queue<TreeNode*> q;
        q.push(root);
        while (q.size()){
            TreeNode* const temp = q.front();
            q.pop();
            if (!temp) continue;
            std::swap(temp->left,temp->right);
            q.push(temp->left);
            q.push(temp->right);
        }
        return root;
    }
};
