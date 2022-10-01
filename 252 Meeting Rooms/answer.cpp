#include <vector>
#include <algorithm>

class Solution {
public:
    bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
      if (intervals.size() < 2) return true;
      std::sort(intervals.begin(),intervals.end());
      for (int i=0; i<intervals.size()-1; ++i){
        if (intervals[i][1] > intervals[i+1][0]) return false;
      }
      return true;
    }
};