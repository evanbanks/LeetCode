class Solution {
    bool test(vector<int>& piles, int h, double k){
        int ans = 0;
        for (int i : piles) ans += ceil(i/k);
        return ans <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0;
        for (int i : piles) right = max(right,i);
        while (left < right){
            int mid = (left + right) / 2;
            if (test(piles,h,mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
