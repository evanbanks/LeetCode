class Solution {
public:
    int hammingWeight(unsigned int n) {
        int bits = 0;
        for (;n;++bits) n &= n-1;
        return bits;
    }
};