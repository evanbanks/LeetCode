class Solution {
    std::unordered_set<int> visited;

    bool dfs(const int i, const int p, const std::vector<std::vector<int>>& adj){
        visited.insert(i);
        for (const int a : adj[i]){
            if (visited.find(a) == visited.end()){
                if (!dfs(a,i,adj)) return false;
            } else if (a != p) return false;
        }
        return true;
    }
    
public:
    bool validTree(const int n, const std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n,std::vector<int>{});
        for (const auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0,-1,adj) && visited.size() == n;
    }
};
