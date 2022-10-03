#include <vector>
#include <queue>
#include <algorithm>

struct {
    bool operator() (const std::vector<int>& l, const std::vector<int>& r) const { return l[1] > r[1]; }
} less_comp;

class Solution {
public:
  int minMeetingRooms(std::vector<std::vector<int>>& in) {
    int rooms = 1;
    int free_rooms = 0;
    std::sort(in.begin(),in.end());
    std::priority_queue q(in.begin(),in.begin()+1,less_comp);
    for (size_t i=1; i<in.size(); ++i){
      while (!q.empty() && in[i][0] >= q.top()[1]){
        ++free_rooms;
        q.pop();
      }
      --free_rooms;
      if (free_rooms < 0){
        ++free_rooms;
        ++rooms;
      }
      q.push(in[i]);
    }
    return rooms;
  }
};