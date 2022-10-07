class Solution {
public:
  char nextGreatestLetter(const vector<char>& letters, const char target) {
    int l = 0, r = letters.size()-1;
    while (l <= r){
      int mid = (l+r)/2;
      if (letters[mid] > target){
        if (mid > 0 && letters[mid-1] <= target){
          return letters[mid];
        }
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    return letters[0];
  }
};
