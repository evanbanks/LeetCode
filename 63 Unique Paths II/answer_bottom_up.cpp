class Solution {
public:
    int uniquePathsWithObstacles(const std::vector<std::vector<int>>& grid) {
        std::vector<int> tab(grid[0].size(),0);
        for (int i=0; i<grid[0].size(); ++i) if (!grid[0][i]) tab[i] = 1; else break;
        for (int i=1; i<grid.size(); ++i){
            int prev = 0;
            for (int j=0; j<grid[0].size(); ++j){
                if (grid[i][j]) tab[j] = 0;
                else tab[j] = tab[j] + prev;
                prev = tab[j];
            }
        }
        return tab[grid[0].size()-1];
    }
};
