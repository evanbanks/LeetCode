class Solution {
    int time = 0;
    std::unordered_set<int> visited;
    std::unordered_map<int,int> oldest;
    std::vector<std::vector<int>> bridges;

    void dfs(const int n, const int p, const std::vector<std::vector<int>>& adj){
        visited.insert(n);
        int ct = oldest[n] = time++;
        for (const int a : adj[n]){
            if (!visited.count(a)){
                dfs(a,n,adj);
                if (oldest[a] > ct){
                    bridges.push_back({n,a});
                }
            } 
            if (a != p && oldest[a] < oldest[n]) oldest[n] = oldest[a];
        }
    }
public:
    std::vector<std::vector<int>> criticalConnections(const int n, const std::vector<std::vector<int>>& connections) {
        std::vector<std::vector<int>> adj(n);
        for (const auto& c : connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        dfs(0,-1,adj);
        return bridges;
    }
};
