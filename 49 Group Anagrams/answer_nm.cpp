class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
        std::unordered_map<std::string,std::vector<std::string>> anagrams {};
        for (size_t i=0; i<strs.size(); ++i){
            int str_freq[26] {};
            for (const auto& c : strs[i]) ++str_freq[c - 'a'];
            std::string hash;
            for (int i=0; i<26; ++i){
                hash += (char)('a'+i) + std::to_string(str_freq[i]);
            }
            anagrams[hash].push_back(strs[i]);
        }
        std::vector<std::vector<std::string>> sol;
        for (const auto& [key,val] : anagrams){
            sol.push_back(val);
        }
        return sol;
    }
};
