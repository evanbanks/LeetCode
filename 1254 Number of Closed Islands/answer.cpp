class Solution {
    bool good = true;
    const int bounds[4] = {-1,1,0,0};
    unsigned m, n;

    void dfs(const unsigned i, const unsigned j, std::vector<std::vector<int>>& grid){
        if (i < n && j < m){
            if (!grid[i][j]){
                grid[i][j] = 1;
                for (size_t k=0; k<4; ++k) dfs(i+bounds[k],j+bounds[3-k],grid);
            }
        } else {
            good = false;
        }
    }
public:
    int closedIsland(std::vector<std::vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (size_t i=0; i<n; ++i){
            for (size_t j=0; j<m; ++j){
                if (!grid[i][j]){
                    good = true;
                    dfs(i,j,grid);
                    if (good) ++ans;
                }
            }
        }
        return ans;
    }
};
