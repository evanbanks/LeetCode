class Solution {
    bool enclave = true;
    int cells = 0;
    int n, m;
    const int os[4] = {1,-1,0,0};
    bool is_valid(unsigned i, unsigned j) {return i < n && j < m;}
    bool is_edge(unsigned i, unsigned j) {return !i || !j || i == n-1 || j == m-1;}

    void dfs(const int i, const int j, std::vector<std::vector<int>>& grid){
        grid[i][j] = 0; 
        ++cells;
        if (is_edge(i,j)) enclave = false;
        for (int k=0; k<4; ++k){
            int oi = i+os[k], oj = j + os[3-k];
            if (is_valid(oi,oj) && grid[oi][oj]) dfs(oi,oj,grid);
        }
    }

public:
    int numEnclaves(std::vector<std::vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (size_t i=0; i<n; ++i){
            for (size_t j=0; j<m; ++j){
                if (grid[i][j]){
                    dfs(i,j,grid);
                    if (enclave) ans += cells;
                    cells = 0;
                    enclave = true;
                }
            }
        }
        return ans;
    }
};
