#include <vector>

void PostOrderHelper(Node* n, std::vector<int>& post_order){
    if (!n) return;
    for (const auto& c : n->children){
        PostOrderHelper(c,post_order);
    }
    post_order.push_back(n->val);
}

class Solution {
public:
    vector<int> postorder(Node* root) {
        std::vector<int> post_order;
        PostOrderHelper(root,post_order);
        return post_order;
    }
};