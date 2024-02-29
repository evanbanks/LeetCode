class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (q.size()){
            int size = q.size();
            int prev = level % 2 ? 1e7 : 0;
            while (size--){
                TreeNode* f = q.front();
                q.pop();
                if (!f) continue;
                if (f->val % 2 == level % 2) return false;
                if ((level % 2 && f->val >= prev) || (level % 2 == 0 && f->val <= prev)) return false;
                prev = f->val;
                q.push(f->left);
                q.push(f->right);
            }
            ++level;
        }
        return true;
    }
};
