#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& arr) {
        int left = 0, right = arr.size()-1;
        for (int i=0; i<=right; ++i){
            if (arr[i] == 0){
                std::swap(arr[i],arr[left]);
                ++left;
            } else if (arr[i] == 2){
                std::swap(arr[i],arr[right]);
                --right;
                --i;
            }
        }
    }
};