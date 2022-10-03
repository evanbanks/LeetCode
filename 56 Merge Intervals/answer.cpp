#include <vector>
#include <algorithm>

inline bool comp(const std::vector<int>& a, const std::vector<int>& b) {return a[0] < b[0];}

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& in) {
      std::sort(in.begin(),in.end(),comp);
      std::vector<std::vector<int>> mi = {in[0]};
      for (size_t i=1, j=0; i<in.size(); ++i){
        if (mi[j][1] < in[i][0]){
          mi.push_back(in[i]);
          ++j;
        } else {
          mi[j][1] = std::max(mi[j][1],in[i][1]);
        }
      }
      return mi;
    }
};