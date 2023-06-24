class Solution {
public:
    Node* lowestCommonAncestor(Node* const p, Node* const q) {
        Node* a = p, *b = q;
        while (a != b){
            a = a ? a->parent : q;
            b = b ? b->parent : p;
        }
        return a;
    }
};
