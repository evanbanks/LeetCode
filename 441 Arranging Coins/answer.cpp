class Solution {
public:
  int arrangeCoins(const int n) {
    int l = 0, r = n;
    while (l<=r){
      long mid = (l+r)/2;
      long sum = (mid*(mid+1))/2;
      if (sum == n) return mid;
      if (sum < n){
        l = mid+1;
      } else {
        r = mid-1;
      }
    }
    return r;
  }
};
