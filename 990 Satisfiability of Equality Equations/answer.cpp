class DJS {
    std::vector<char> parent;
    std::vector<char> rank;
public:
    DJS(int n) : parent(n), rank(n,0) {
        std::iota(parent.begin(),parent.end(),0);
    }
    int Find(int x){
        while (x != parent[x]){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
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
};

class Solution {
public:
    bool equationsPossible(const std::vector<std::string>& equations) {
        DJS uf(256);
        for (const auto& e : equations){
            if (e[1] == '=') uf.Unite(e[0],e[3]);
        }
        for (const auto& e : equations){
            if (e[1] == '!' && uf.Find(e[0]) == uf.Find(e[3])) return false;
        }
        return true;
    }
};
