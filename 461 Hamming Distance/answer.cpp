class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        x ^= y;
        while (x){
            if (x&1) ++ans;
            x >>= 1;
        }
        return ans;
    }
};
