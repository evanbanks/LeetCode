class Solution {
public:
    int reachableNodes(const std::vector<std::vector<int>>& edges, const int maxMoves, const int n) {
        std::vector<std::vector<std::array<int,3>>> adj(n);
        for (int i=0; i<edges.size(); ++i){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2],i});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2],i});
        }
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> q;
        std::unordered_set<int> visited;
        std::unordered_map<int,int> flow;
        q.push({0,0});
        while (q.size()){
            auto [dist,vert] = q.top();
            q.pop();
            if (visited.find(vert) != visited.end()) continue;
            visited.insert(vert);
            for (const auto& a : adj[vert]){
                int new_dist = dist + a[1] + 1;
                if (new_dist <= maxMoves){
                    q.push({new_dist,a[0]});
                }
                flow[a[2]] = std::min(a[1], flow[a[2]] + maxMoves - dist);
            }
        }
        int ans = visited.size();
        for (const auto& [f,s] : flow) ans += s;
        return ans;
    }
};
