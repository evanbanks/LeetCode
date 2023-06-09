class Solution {
    int* color = nullptr;
    int* visited = nullptr;

    bool bfs(const std::vector<std::vector<int>>& graph, const int src) {
        std::queue<int> q;
        visited[src] = true;
        color[src] = 0;
        q.push(src);
        while (q.size()){
            int f = q.front();
            q.pop();
            for (const int a : graph[f]){
                if (!visited[a]){
                    visited[a] = true;
                    color[a] = !color[f];
                    q.push(a);
                } else if (color[a] == color[f]) return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(const std::vector<std::vector<int>>& graph) {
        color = new int[graph.size()];
        visited = new int[graph.size()]();
        std::fill_n(color, graph.size(), -1);
        for (int i=0; i<graph.size(); ++i){
            if (!visited[i] && !bfs(graph,i)) return false;
        }
        return true;
    }
};
