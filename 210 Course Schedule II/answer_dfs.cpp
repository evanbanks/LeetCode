class Solution {
    std::unordered_set<int> visited;
    std::unordered_set<int> processed;
    std::vector<int> sol;

    bool dfs(const std::vector<std::vector<int>>& adj, const int src){
        visited.insert(src);
        for (const int a : adj[src]){
            if (visited.find(a) == visited.end()){
                if (dfs(adj,a)) return true;
            } else if (processed.find(a) == processed.end()) return true;
        }
        sol.push_back(src);
        processed.insert(src);
        return false;
    }
public:
    sd::vector<int> findOrder(const int numCourses, const std::vector<std::vector<int>>&  prerequisites) {
        std::vector<std::vector<int>> adj(numCourses,std::vector<int>{});
        for (const auto& p : prerequisites){
            adj[p[0]].push_back(p[1]);
        }
        for (int i=0; i<numCourses; ++i){
            if (visited.find(i) == visited.end() && dfs(adj,i)) return {};
        }
        return sol;
    }
};
