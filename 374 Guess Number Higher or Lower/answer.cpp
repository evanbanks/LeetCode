class Solution {
public:
  int guessNumber(int n) {
    int left = 1, right = n;
    while (true){
      int mid = left + (right - left) / 2;
      int g = guess(mid);
      if (!g) return mid;
      if (g == 1) left = mid + 1;
      else right = mid - 1;
    }
  }
};
