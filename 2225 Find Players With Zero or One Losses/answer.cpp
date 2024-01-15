class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> winners;
        unordered_map<int,int> one_losses;
        for (auto& m : matches){
            winners.insert(m[0]);
            ++one_losses[m[1]];
        }
        for (auto& m : matches){
            winners.erase(m[1]);
        }
        vector<vector<int>> ans(2);
        for (int i : winners){
            ans[0].push_back(i);
        }
        for (auto& [f,s] : one_losses){
            if (s == 1) ans[1].push_back(f);
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};
