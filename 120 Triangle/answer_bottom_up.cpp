class Solution {
public:
    int minimumTotal(const std::vector<std::vector<int>>& triangle) {
        std::vector<int> tab(triangle[triangle.size()-1]);
        for (int i=triangle.size()-2; i>=0; --i){
            for (size_t j=0; j<triangle[i].size(); ++j){
                tab[j] = triangle[i][j] + std::min(tab[j],tab[j+1]);
            }
        }
        return tab[0];
    }
};
