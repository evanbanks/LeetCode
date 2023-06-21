class Solution {
public:
    bool validPath(const int n, const std::vector<std::vector<int>>& edges, const int source, const int destination) {
        std::vector<std::vector<int>> adj(n,std::vector<int>{});
        std::unordered_set<int> visited;
        for (const auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        std::stack<int> s;
        s.push(source);
        visited.insert(source);
        while (s.size()){
            int t = s.top();
            if (t == destination) return true;
            s.pop();
            for (const int a : adj[t]){
                if (visited.find(a) == visited.end()){
                    visited.insert(a);
                    s.push(a);
                }
            }
        }
        return false;
    }
};
