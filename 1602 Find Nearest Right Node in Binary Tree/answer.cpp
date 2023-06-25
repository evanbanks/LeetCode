class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* const root, TreeNode* const u) {
        std::queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while (q.size()){
            TreeNode* f = q.front();
            q.pop();
            if (f){
                if (f == u) return q.front();
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            } else if (q.size()) q.push(nullptr);
        }
        return nullptr;
    }
};
