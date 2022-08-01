#include <vector>

void PreorderHelper(Node* n, std::vector<int>& vec){
    if (!n) return;
    vec.push_back(n->val);
    for (const auto& c : n->children){
        PreorderHelper(c, vec);
    }
}


class Solution {
public:
    vector<int> preorder(Node* root) const {
        std::vector<int> vec;
        PreorderHelper(root, vec);
        return vec;
    }
};