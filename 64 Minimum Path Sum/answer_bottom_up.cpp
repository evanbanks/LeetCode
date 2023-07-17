class Solution {
public:
    int minPathSum(const std::vector<std::vector<int>>& grid) {
        std::vector<int> tab(grid[0].size());
        tab[0] = grid[0][0];
        for (size_t i=1; i<grid[0].size(); ++i) tab[i] = grid[0][i] + tab[i-1];
        for (size_t i=1; i<grid.size(); ++i){
            int prev = grid[i][0] + tab[0];
            for (size_t j=0; j<grid[0].size(); ++j){
                tab[j] = grid[i][j] + std::min(tab[j],prev);
                prev = tab[j];
            }
        }
        return tab[grid[0].size()-1];
    }
};
