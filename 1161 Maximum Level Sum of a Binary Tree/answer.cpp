class Solution {
public:
    int maxLevelSum(TreeNode* const root) {
        std::pair<int,int> ms = {1,root->val};
        int level = 1;
        std::queue<TreeNode*> q;
        q.push(root);
        while (q.size()){
            size_t ls = q.size();
            int sum = 0;
            for (size_t i=0; i<ls; ++i){
                TreeNode* f = q.front();
                q.pop();
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
                sum += f->val;
            }
            if (sum > ms.second) ms = {level,sum};
            ++level;
        }
        return ms.first;
    }
};
