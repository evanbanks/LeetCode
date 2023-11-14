class Solution {
public:
    string removeVowels(const string& s) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        string ans;
        for (char c : s) if (!vowels.count(c)) ans.push_back(c);
        return ans;
    }
};
