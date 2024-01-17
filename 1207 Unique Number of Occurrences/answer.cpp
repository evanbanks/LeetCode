class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (int i : arr) ++freq[i];
        unordered_set<int> se;
        for (auto& [f,s] : freq) se.insert(s);
        return se.size() == freq.size();
    }
};
