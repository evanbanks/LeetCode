class Solution {
public:
    double maxProbability(const int n, const std::vector<std::vector<int>>& edges, const std::vector<double>& succProb, const int start, const int end) {
        std::vector<std::vector<std::pair<int,double>>> adj(n);
        std::vector<double> dist(n,0);
        for (size_t i=0; i<edges.size(); ++i){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        std::priority_queue<std::pair<double,int>> q;
        q.push({1,start});
        dist[start] = 1;
        while (q.size()){
            auto [up,u] = q.top();
            q.pop();
            if (u == end) return dist[end];
            for (const auto [v,vp] : adj[u]){
                if (dist[v] < dist[u] * vp){
                    dist[v] = dist[u] * vp;
                    q.push({dist[v],v});
                }
            }
        }
        return 0;
    }
};
