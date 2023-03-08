class Solution {
public:
    bool containsNearbyDuplicate(const std::vector<int>& nums, const int k) {
        std::unordered_set<int> set;
        for (int ws=0, we=0; we<nums.size(); ++we){
            if (set.find(nums[we]) != set.end()) return true;
            set.insert(nums[we]);
            if (we-ws==k){
                set.erase(nums[ws++]);
            }
        }
        return false;
    }
};
