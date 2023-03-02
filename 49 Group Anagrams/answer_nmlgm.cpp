class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
        std::unordered_map<std::string,std::vector<std::string>> anagrams;
        for (size_t i=0; i<strs.size(); ++i){
            std::string s = strs[i];
            std::sort(s.begin(),s.end());
            anagrams[s].push_back(strs[i]);
        }
        std::vector<std::vector<std::string>> sol;
        for (const auto& [key,val] : anagrams){
            sol.push_back(val);
        }
        return sol;
    }
};
