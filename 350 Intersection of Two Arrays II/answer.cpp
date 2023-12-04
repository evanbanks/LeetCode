class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> s;
        for (int i : nums1) ++s[i];
        vector<int> ans;
        for (int i : nums2){
            if (s[i]-- > 0) ans.push_back(i);
        }
        return ans;
    }
};
