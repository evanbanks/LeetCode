class Solution {
public:
    std::vector<int> findSmallestSetOfVertices(const int n, const std::vector<std::vector<int>>& edges) {
        std::unordered_set<int> s;
        for (int i=0; i<n; ++i) s.insert(i);
        for (const auto& e : edges) s.erase(e[1]);
        return std::vector<int>(s.begin(),s.end());
    }
};
