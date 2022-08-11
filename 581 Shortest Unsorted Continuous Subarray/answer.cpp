#include <vector>
#include <limits>

class Solution {
public:
    int findUnsortedSubarray(const std::vector<int>& arr) {
        int ws = -1, we = arr.size();
        int curr = std::numeric_limits<int>::max();
        for(int i=arr.size()-1; i>=0; --i){
            if(curr >= arr[i]) curr = arr[i];
            else ws = i;
        }
        curr = std::numeric_limits<int>::min();
        for(int i=0; i<arr.size(); ++i){
            if(curr <= arr[i]) curr = arr[i];
            else we = i;
        }
        if (ws == -1) return 0;
        return we-ws+1;
    }
};