class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> rows(grid.size());
        vector<int> cols(grid[0].size());
        for (int i=0; i<grid.size(); ++i){
            for (int j=0; j<grid[0].size(); ++j){
                if (grid[i][j]){
                    ++rows[i];
                    ++cols[j];
                }
            }
        }
        vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size()));
        for (int i=0; i<grid.size(); ++i){
            for (int j=0; j<grid[0].size(); ++j){
                ans[i][j] = 2 * rows[i] + 2 * cols[j] - grid.size() - grid[0].size();
            }
        }
        return ans;
    }
};
