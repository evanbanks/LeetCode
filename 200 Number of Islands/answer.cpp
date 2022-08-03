#include <vector>

void dfs(std::vector<std::vector<char>>& grid, int row, int col){
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0'){
        return;
    }
    grid[row][col] = '0';
    dfs(grid,row-1,col);
    dfs(grid,row+1,col);
    dfs(grid,row,col-1);
    dfs(grid,row,col+1);
}


class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int num_islands = 0;
        for (size_t i=0; i<grid.size(); ++i){
            for (size_t j=0; j<grid[0].size(); ++j){
                if (grid[i][j] == '1'){
                    num_islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return num_islands;
    }
};