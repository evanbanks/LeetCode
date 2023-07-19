class Solution {
public:
    int minFallingPathSum(const std::vector<std::vector<int>>& matrix) {
        std::vector<int> tab(matrix[matrix.size()-1]);
        for (int i=matrix.size()-2; i >= 0; --i){
            int left;
            for (size_t j=0; j<matrix.size(); ++j){
                int min = tab[j];
                if (j) min = std::min(min,left);
                left = tab[j];
                if (j < matrix.size()-1) min = std::min(min,tab[j+1]);
                tab[j] = matrix[i][j] + min;
            }
        }
        return *std::min_element(tab.begin(),tab.end());
    }
};
