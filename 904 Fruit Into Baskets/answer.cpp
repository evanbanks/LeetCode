#include <vector>
#include <unordered_map>

class Solution {
public:
    int totalFruit(const std::vector<int>& arr) {
    int max_count = 0;
    int count = 0;
    std::unordered_map<int, int> freq;
    for (int ws=0, we=0; we<arr.size(); ++we){
      freq[arr[we]]++;
      count++;
      while (freq.size() > 2){
        freq[arr[ws]]--;
        if (!freq[arr[ws]]){
          freq.erase(arr[ws]);
        }
        count--;
        ws++;
      }
      max_count = std::max(max_count, count);
    }
    return max_count;
    }
};