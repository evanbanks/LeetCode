class Solution {
public:
    std::string removeDuplicates(const std::string& str) {
        std::stack<char> s;
        for (int i=0; i<str.size(); ++i){
            if (s.size() && s.top() == str[i]){
                s.pop();
            } else {
                s.push(str[i]);
            }
        }
        std::string ans;
        while (s.size()) {ans += s.top(); s.pop();}
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};
