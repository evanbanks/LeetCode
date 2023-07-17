class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < n) std::swap(m,n);
        std::vector<int> tab(n,1);
        for (int i=1; i<m; ++i){
            int prev = tab[0];
            for (int j=1; j<n; ++j){
                tab[j] = tab[j] + prev;
                prev = tab[j];
            }
        }
        return tab[n-1];
    }
};
