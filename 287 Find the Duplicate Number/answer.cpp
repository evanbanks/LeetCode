class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size()-1;
        while (left < right){
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int i : nums) if (i <= mid) ++cnt;
            if (cnt > mid) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
