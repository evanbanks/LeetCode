#include <vector>
#include <queue>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        std::vector<std::vector<int>> level_order;
        std::queue<TreeNode*> q;
        q.push(root);
        int level_size =1;
        while(!q.empty()){
            int temp = 0;
            std::vector<int> vec;
            while(level_size--){
                TreeNode* c = q.front();
                q.pop();
                vec.push_back(c->val);
                if (c->left) {
                    q.push(c->left);
                    temp++;
                }
                if (c->right) {
                    q.push(c->right);
                    temp++;
                }
            }
            level_order.push_back(vec);
            level_size=temp;

        }
        return level_order;
    }
};