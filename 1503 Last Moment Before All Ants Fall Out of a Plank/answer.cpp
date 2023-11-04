class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int max_left = 0;
        int min_right = n;
        for (int i : left) max_left = max(max_left,i);
        for (int i : right) min_right = min(min_right,i);
        return max(max_left,n-min_right);
    }
};
