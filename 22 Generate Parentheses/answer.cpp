class Solution {
    std::string curr;
    std::vector<std::string> sol;

    void dfs(const int o, const int c){
        if (!c){
            sol.push_back(curr);
        } else {
            if (o){
                curr.push_back('(');
                dfs(o-1,c);
                curr.pop_back();
            }
            if (o < c){
                curr.push_back(')');
                dfs(o,c-1);
                curr.pop_back();
            }
        }
    }
public:
    std::vector<std::string> generateParenthesis(const int n) {
        dfs(n,n);
        return sol;
    }
};
