#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> preorder(Node* root) const {
        if (!root) return {};
        std::stack<Node*> stck;
        std::vector<int> vec;
        stck.push(root);
        while(!stck.empty()){
            Node* top = stck.top();
            stck.pop();
            vec.push_back(top->val);
            for (int i=top->children.size()-1; i>=0; --i){
                stck.push(top->children[i]);
            }
        }
        return vec;
    }
};