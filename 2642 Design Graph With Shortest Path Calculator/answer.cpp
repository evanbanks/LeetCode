class Graph {
    vector<vector<pair<int,int>>> g;
public:
    Graph(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for (auto& e : edges){
            g[e[0]].push_back({e[1],e[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(g.size(),1e9);
        dist[node1] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,node1});
        while (pq.size()){
            auto [du,u] = pq.top();
            pq.pop();
            if (du > dist[u]) continue;
            if (u == node2) return dist[u];
            for (auto& [v,w] : g[u]){
                if (dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v],v});
                }
            }
        }
        return -1;
    }
};
