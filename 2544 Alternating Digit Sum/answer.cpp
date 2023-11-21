class Solution {
public:
    int alternateDigitSum(int n) {
        int ans = 0;
        int sign = 1;
        while (n){
            ans += (n % 10) * sign;
            sign *= -1;
            n /= 10;
        }
        return ans * -1 * sign;
    }
};
