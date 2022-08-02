#include<vector>

class Solution {
public:
    int nearestValidPoint(const int x, const int y, const std::vector<std::vector<int>>& p) {
        int min_dist = __INT32_MAX__;
        int min_index = -1;
        for (int i=0; i<p.size(); ++i){
            if (x == p[i][0] || y == p[i][1]){
                int man_dist = std::abs(x-p[i][0])+std::abs(y-p[i][1]);
                if (man_dist < min_dist){
                    min_dist = man_dist;
                    min_index = i;
                }
            }
        }
        return min_index;
    }
};