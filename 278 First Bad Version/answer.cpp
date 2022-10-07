class Solution {
public:
    int firstBadVersion(const int n) {
      int l = 0, r = n;
      while (true){
        int mid = l +(r-l)/2;
        if (isBadVersion(mid)){
          if (!isBadVersion(mid-1)) return mid;
          r = mid-1;
        } else {
          l = mid+1;
        }
      }
    }
};
