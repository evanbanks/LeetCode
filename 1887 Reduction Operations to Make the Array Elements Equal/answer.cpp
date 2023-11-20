class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int maxe = *max_element(nums.begin(),nums.end());
        int arr[maxe+1];
        memset(arr,0,sizeof(arr));
        for (int i : nums) ++arr[i];
        int ans = 0;
        int diff = -1;
        for (int i=0; i<=maxe; ++i){
            if (arr[i]){
                ++diff;
                ans += arr[i] * diff;
            }
        }
        return ans;
    }
};
