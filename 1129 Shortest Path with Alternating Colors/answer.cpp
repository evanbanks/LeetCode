class Solution {
public:
    std::vector<int> shortestAlternatingPaths(const int n, const std::vector<std::vector<int>>& redEdges, const std::vector<std::vector<int>>& blueEdges) {
        std::vector<std::vector<std::pair<int,int>>> adj(n);
        for (const auto& r : redEdges) adj[r[0]].push_back({r[1],0});
        for (const auto& b : blueEdges) adj[b[0]].push_back({b[1],1});

        std::vector<int> dist(n,-1);
        dist[0] = 0;
        std::unordered_set<int> visited[2];
        int breadth = 0;
        std::queue<std::pair<int,int>> q;
        q.push({0,-1});
        while(q.size()){
            size_t sz = q.size();
            ++breadth;
            while (sz--){
                auto [u,uc] = q.front();
                q.pop();
                for (const auto& [v,vc] : adj[u]){
                    if (uc != vc && visited[vc].find(v) == visited[vc].end()){
                        visited[vc].insert(v);
                        q.push({v,vc});
                        if (dist[v] == -1) dist[v] = breadth;
                    }
                }
            }
        }
        return dist;
    }
};
