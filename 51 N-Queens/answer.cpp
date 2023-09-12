class Solution {
    void dfs(int i, int n, vector<int>& cols, vector<bool>& diag, vector<bool>& rdiag, vector<vector<string>>& ans, vector<string>& board){
        if (i == n){
            ans.push_back(board);
            return;
        }
        for (int j=0; j<n; ++j){
            if (cols[j] || diag[n+i-j] || rdiag[i+j]) continue;
            board[i][j] = 'Q';
            cols[j] = diag[n+i-j] = rdiag[i+j] = true;
            dfs(i+1,n,cols,diag,rdiag,ans,board);
            board[i][j] = '.';
            cols[j] = diag[n+i-j] = rdiag[i+j] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> diag(2*n);
        vector<bool> rdiag(2*n);
        vector<int> cols(n);
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        dfs(0,n,cols,diag,rdiag,ans,board);
        return ans;
    }
};
