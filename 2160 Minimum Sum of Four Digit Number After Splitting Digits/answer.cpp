#include <algorithm>

class Solution {
public:
    int minimumSum(int num) {
        int arr[4];
        size_t i=0;
        while (num){
            arr[i++] = num % 10;
            num /= 10;
        }
        std::sort(arr,arr+4);
        return arr[0]*10+arr[2] + arr[1]*10+arr[3];
    }
};