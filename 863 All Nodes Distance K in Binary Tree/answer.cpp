class Solution {
public:
    std::vector<int> distanceK(TreeNode* const root, TreeNode* const target, const int k) {
        std::unordered_map<int,std::vector<int>> adj;
        std::stack<TreeNode*> s;
        s.push(root);
        while (s.size()){
            TreeNode* t = s.top();
            s.pop();
            if (t->left){
                adj[t->val].push_back(t->left->val);
                adj[t->left->val].push_back(t->val);
                s.push(t->left);
            }
            if (t->right){
                adj[t->val].push_back(t->right->val);
                adj[t->right->val].push_back(t->val);
                s.push(t->right);
            }
        }
        int dist = 1;
        std::vector<int> ans;
        std::unordered_set<int> visited;
        visited.insert(target->val);
        std::queue<int> q;
        q.push(target->val);
        while (q.size()){
            if (dist == k+1){
                while (q.size()) {ans.push_back(q.front()); q.pop();}
                return ans;
            }
            size_t sz = q.size();
            while (sz--){
                int f = q.front();
                q.pop();
                for (const int a : adj[f]){
                    if (visited.find(a) == visited.end()){
                        visited.insert(a);
                        q.push(a);
                    }
                }
            }
            ++dist;
        }
        return ans;
    }
};
