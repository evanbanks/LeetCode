#include <math.h>

int ss(int n){
    int sum = 0;
    while (n) {
        sum += std::pow(n %10,2);
        n /= 10;
    }
    return sum;
}


class Solution {
public:
    bool isHappy(const int n) {
        int slow = ss(n);
        int fast = ss(slow);
        while (slow != fast){
            slow = ss(slow);
            fast = ss(ss(fast));
        }
        return slow == 1;
    }
};