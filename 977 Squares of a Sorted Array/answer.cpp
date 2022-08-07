#include <vector>

class Solution {
public:
    std::vector<int> sortedSquares(const std::vector<int>& arr) {
        std::vector<int> squares(arr.size());
        int highest_index = arr.size()-1;
        int left = 0, right = highest_index;
        while (left <= right){
            if (std::abs(arr[left]) > std::abs(arr[right])){
                squares[highest_index--] = arr[left] * arr[left];
                ++left;
            } else {
                squares[highest_index--] = arr[right] * arr[right];
                --right;
            }
        }
        return squares;
    }
};