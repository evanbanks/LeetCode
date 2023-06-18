class Solution {
    std::string curr;
    std::vector<std::string> sol;

    void dfs(const int k, const std::string& s){
        if (k == s.size()){
            sol.push_back(curr);
        } else {
            char c = s[k];
            if (std::isalpha(c)){
                curr.push_back(c);
                dfs(k+1,s);
                curr.pop_back();
                c += c < 97 ? 32 : -32;
            }
            curr.push_back(c);
            dfs(k+1,s);
            curr.pop_back();
        }
    }
public:
    std::vector<std::string> letterCasePermutation(const std::string& s) {
        dfs(0,s);
        return sol;
    }
};
