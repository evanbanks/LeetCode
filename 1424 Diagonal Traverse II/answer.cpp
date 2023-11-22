class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        queue<pair<int,int>> q;
        q.push({0,0});
        while (q.size()){
            auto [x,y] = q.front();
            q.pop();
            ans.push_back(nums[x][y]);
            if (x < nums.size() - 1 && !y) q.push({x+1,y});
            if (y < nums[x].size() - 1) q.push({x,y+1});
        }
        return ans;
    }
};
