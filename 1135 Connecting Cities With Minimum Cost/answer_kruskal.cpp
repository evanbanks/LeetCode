class DJS {
    std::vector<int> rank;
    std::vector<int> parent;
public:
    DJS(int n) : rank(n,0), parent(n) {
        std::iota(parent.begin(),parent.end(),0);
    }

    void Unite(const int x, const int y){
        int xp = Find(x);
        int yp = Find(y);

        if (xp == yp) return;

        if (rank[xp] > rank[yp]){
            parent[yp] = xp;
        } else {
            parent[xp] = yp;
            if (rank[xp] == rank[yp]) ++rank[yp];
        }
    }

    int Find(int x){
        while (x != parent[x]){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};

class Solution {
public:
    int minimumCost(const int n, std::vector<std::vector<int>>& connections) {
        std::sort(connections.begin(),connections.end(),[](const std::vector<int>& a, const std::vector<int>& b){return a[2] < b[2];});
        DJS uf(n+1);
        int cost = 0, edges = 0;
        for (const auto& c : connections){
            if (uf.Find(c[0]) == uf.Find(c[1])) continue;
            uf.Unite(c[0],c[1]);
            cost += c[2];
            ++edges;
            if (edges == n-1) return cost;
        }
        return -1;
    }
};
