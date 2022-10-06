class Solution {
public:
  int mySqrt(const int x) {
    if (x < 2 ) return x;
    int l = 1, r = x/2;
    while (l <= r){
      long mid = (l+r)/2;
      if (mid*mid > x){
        r = mid-1;
      } else if ((mid+1)*(mid+1) > x){
        return mid;
      } else {
        l = mid+1;
      }
    }
    return 0;
  }
};