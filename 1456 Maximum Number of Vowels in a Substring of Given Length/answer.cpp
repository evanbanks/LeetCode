class Solution {
public:
    int maxVowels(const std::string& s, const int k) {
        int ans = 0, curr = 0;
        const std::unordered_set<char> vowels = {'a','e','i','o','u'};
        for (int ws=0, we=0; we<s.size(); ++we){
            if (vowels.find(s[we]) != vowels.end()) ++curr;
            if (we >= k-1){
                ans = std::max(ans,curr);
                if (vowels.find(s[ws++]) != vowels.end()) --curr;
            }
        }
        return ans;
    }
};
