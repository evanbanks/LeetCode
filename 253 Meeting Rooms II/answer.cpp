#include <vector>
#include <queue>
#include <algorithm>

struct {
    bool operator() (const std::vector<int>& l, const std::vector<int>& r) const { return l[1] > r[1]; }
} less_comp;

class Solution {
public:
  int minMeetingRooms(std::vector<std::vector<int>>& in) {
    size_t rooms = 1;
    std::sort(in.begin(),in.end());
    std::priority_queue q(in.begin(),in.begin()+1,less_comp);
    for (size_t i=1; i<in.size(); ++i){
      while (!q.empty() && in[i][0] >= q.top()[1]){
        q.pop();
      }
      q.push(in[i]);
      rooms = std::max(rooms,q.size());
    }
    return rooms;
  }
};