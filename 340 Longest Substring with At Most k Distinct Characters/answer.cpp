class Solution {
public:
    int lengthOfLongestSubstringKDistinct(const std::string& str, const int k) {
        std::unordered_map<char,int> freq;
        int max = 0;
        for (int ws=0, we=0; we<str.size(); ++we){
            ++freq[str[we]];
            if (freq.size() > k){
                --freq[str[ws]];
                if (!freq[str[ws]]) freq.erase(str[ws]);
                ++ws;
            }
            max = std::max(max,we-ws+1);
        }
        return max;
    }
};
