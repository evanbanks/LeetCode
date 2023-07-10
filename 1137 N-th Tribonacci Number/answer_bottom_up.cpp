class Solution {
public:
    int tribonacci(const int n) {
        if (n < 3) return n ? 1 : 0;
        int t3 = 0, t2 = 1, t1 = 1, curr;
        for (int i=3; i<=n; ++i){
            curr = t3 + t2 + t1;
            t3 = t2;
            t2 = t1;
            t1 = curr;
        }
        return curr;
    }
};
