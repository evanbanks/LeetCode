class Solution {
    std::unordered_set<int> visited;
    void dfs(const int n, const std::vector<std::vector<int>>& isConnected){
        visited.insert(n);
        for (size_t i=0; i<isConnected.size(); ++i){
            if (isConnected[n][i] && visited.find(i) == visited.end()){
                dfs(i,isConnected);
            }
        }
    }
public:
    int findCircleNum(const std::vector<std::vector<int>>& isConnected) {
        int num_comp = 0;
        for (size_t i=0; i<isConnected.size(); ++i){
            if (visited.find(i) == visited.end()){
                ++num_comp;
                dfs(i,isConnected);
            }
        }
        return num_comp;
    }
};
