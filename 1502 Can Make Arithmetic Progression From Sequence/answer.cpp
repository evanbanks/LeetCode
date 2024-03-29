#include <vector>

class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int dist = arr[1]-arr[0];
        for (int i=2; i<arr.size(); ++i){
            if (arr[i] - arr[i-1] != dist) return false;
        }
        return true;
    }
};