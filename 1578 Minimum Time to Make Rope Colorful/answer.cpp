class Solution {
public:
    int minCost(string& colors, vector<int>& neededTime) {
        int ans = 0;
        for (int i=0, j=1; j<colors.size(); ++j){
            if (colors[i] == colors[j]){
                ans += min(neededTime[i],neededTime[j]);
                if (neededTime[i] < neededTime[j]) i = j;
            } else i = j;
        }
        return ans;
    }
};
