class Solution {
public:
    int deleteAndEarn(const std::vector<int>& nums) {
        std::unordered_map<int,int> freq;
        int max_num = 0;
        for (const int n : nums){
            max_num = std::max(n,max_num);
            freq[n] += n;
        }
        int curr = 0, p1 = 0, p2 = 0;
        for (int i=1; i<=max_num; ++i){
            curr = std::max(freq[i] + p2, p1);
            p2 = p1;
            p1 = curr;
        }
        return curr;
    }
};
