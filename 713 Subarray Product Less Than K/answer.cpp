#include <vector>

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& arr, const int k) {
        int result = 0, product = 1;
        for (size_t ws=0, we=0; we<arr.size(); ++we){
            product *= arr[we];
            while (product >= k && ws <=we){
                product /= arr[ws++];
            }
            result += we-ws+1;
        }
        return result;
    }
};