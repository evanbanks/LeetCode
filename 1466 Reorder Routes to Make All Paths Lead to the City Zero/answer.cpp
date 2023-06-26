class Solution {
public:
    int minReorder(const int n, const std::vector<std::vector<int>>& connections) {
        std::vector<std::vector<std::pair<int,bool>>> adj(n);
        for (const auto& c : connections){
            adj[c[0]].push_back({c[1],true});
            adj[c[1]].push_back({c[0],false});
        }
        int ans = 0;
        std::stack<int> s;
        std::unordered_set<int> visited;
        visited.insert(0);
        s.push(0);
        while (s.size()){
            int t = s.top();
            s.pop();
            for (const auto [a,og] : adj[t]){
                if (visited.find(a) == visited.end()){
                    visited.insert(a);
                    if (og) ++ ans;
                    s.push(a);                   
                }
            }
        }
        return ans;
    }
};
