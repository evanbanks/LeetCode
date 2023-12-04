class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num/2;
        while (left < right){
            int mid = (left + right + 1) / 2;
            if (num / mid < mid) right = mid - 1;
            else left = mid;
        }
        return left * left == num;
    }
};
