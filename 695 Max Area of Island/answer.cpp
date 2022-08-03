#include <vector>

void dfs(std::vector<std::vector<int>>& grid, const int r, const int c, int& length){
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || !grid[r][c]){
        return;
    }
    grid[r][c] = 0;
    length++;
    dfs(grid,r-1,c,length);
    dfs(grid,r+1,c,length);
    dfs(grid,r,c-1,length);
    dfs(grid,r,c+1,length);
}

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int max_length = 0, length = 0;
        for (size_t i=0; i<grid.size(); ++i){
            for (size_t j=0; j<grid[0].size(); ++j){
                if (grid[i][j]){
                    length = 0;
                    dfs(grid, i, j, length);
                    max_length = std::max(max_length, length);
                }
            }
        }
        return max_length;
    }
};