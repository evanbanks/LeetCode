class Solution {
public:
    bool divideArray(std::vector<int>& nums) {
        std::unordered_map<int,int> freq;
        for (const auto& n : nums) ++freq[n];
        for (const auto& [key,value] : freq) if (value % 2) return false;
        return true;
    }
};
