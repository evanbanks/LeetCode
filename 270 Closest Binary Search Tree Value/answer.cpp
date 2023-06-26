class Solution {
public:
    int closestValue(TreeNode* root, const double target) {
        int closest = root->val;
        double min_dist = std::abs(target-root->val);
        while (root){
            double dist = std::abs(target-root->val);
            if (dist <= min_dist){
                closest = dist == min_dist ? std::min(closest,root->val) : root->val;
                min_dist = dist;
            }
            root = root->val > target ? root->left : root->right;
        }
        return closest;
    }
};
