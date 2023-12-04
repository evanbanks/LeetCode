class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> s;
        for (int i : nums1) s.insert(i);
        for (int i : nums2) if (s.count(i)){
            s.erase(i);
            ans.push_back(i);
        }
        return ans;
    }
};
