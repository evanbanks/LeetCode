class Solution {
    std::string curr;
    std::vector<std::string> sol;
    std::unordered_map<char,std::string> to_str = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

    void dfs(const int k, const std::string& digits){
        if (k == digits.size()){
            sol.push_back(curr);
        } else {
            for (const char c : to_str[digits[k]]){
                curr.push_back(c);
                dfs(k+1,digits);
                curr.pop_back();
            }
        }
    }
public:
    std::vector<std::string> letterCombinations(const std::string& digits) {
        if (!digits.size()) return {};
        dfs(0,digits);
        return sol;
    }
};
