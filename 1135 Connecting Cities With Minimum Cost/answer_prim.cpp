class Solution {
public:
    int minimumCost(const int n, const std::vector<std::vector<int>>& connections) {
        std::vector<std::vector<std::pair<int,int>>> adj(n+1);
        for (const auto& c : connections){
            adj[c[0]].push_back({c[1],c[2]});
            adj[c[1]].push_back({c[0],c[2]});
        }
        int cost = 0;
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> q;
        std::unordered_map<int,int> dist;
        for (int i=1; i<=n; ++i) dist.insert({i,std::numeric_limits<int>::max()});
        dist[1] = 0;
        q.push({0,1});
        while (q.size()){
            auto [x,u] = q.top();
            q.pop();
            if (!dist.count(u)) continue;
            cost += dist[u];
            dist.erase(u);
            if (!dist.size()) return cost;
            for (const auto [v,w] : adj[u]){
                if (dist.count(v) && w < dist[v]){
                    dist[v] = w;
                    q.push({w,v});
                }
            }
        }
        return -1;
    }
};
