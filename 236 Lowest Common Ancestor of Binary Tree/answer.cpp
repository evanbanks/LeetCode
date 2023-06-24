class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::unordered_map<TreeNode*,TreeNode*> parent;
        std::stack<TreeNode*> s;
        s.push(root);
        parent[root] = nullptr;
        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()){
            TreeNode* t = s.top();
            s.pop();
            if (t){
                parent[t->left] = t;
                parent[t->right] = t;
                s.push(t->left);
                s.push(t->right);
            }
        }
        std::unordered_set<TreeNode*> pp;
        while (p){
            pp.insert(p);
            p = parent[p];
        }
        while (q){
            if (pp.find(q) != pp.end()) return q;
            q = parent[q];
        }
        return root;
    }
};
