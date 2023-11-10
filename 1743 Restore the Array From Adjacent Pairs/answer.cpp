class Solution {
public:
    vector<int> restoreArray(const vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> m;
        for (auto& a : adjacentPairs) {
            m[a[0]].push_back(a[1]);
            m[a[1]].push_back(a[0]);
        }
        vector<int> ans;
        for (auto& [f,s] : m){
            if (s.size() == 1){
                ans.push_back(f);
                ans.push_back(s.back());
                break;
            }
        }
        for (int i=2; i<=adjacentPairs.size(); ++i){
            if (m[ans.back()][0] != ans[ans.size()-2]){
                ans.push_back(m[ans.back()][0]);
            } else {
                ans.push_back(m[ans.back()][1]);
            }
        }
        return ans;
    }
};
