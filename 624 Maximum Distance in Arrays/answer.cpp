class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int largest = -1e5;
        int smallest = 1e5;
        for (auto& a : arrays){
            ans = max(ans,largest-a[0]);
            ans = max(ans,a.back()-smallest);
            largest = max(largest,a.back());
            smallest = min(smallest,a[0]);
        }
        return ans;
    }
};
