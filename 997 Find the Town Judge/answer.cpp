class Solution {
public:
    int findJudge(const int n, const std::vector<std::vector<int>>& trust) {
        if (n == 1) return 1;
        std::unordered_map<int,int> m;
        for (const auto& t : trust) ++m[t[1]];
        for (const auto& t : trust) m.erase(t[0]);
        return m.size() == 1 && (*m.begin()).second == n-1 ? (*m.begin()).first : -1;
    }
};
