class Solution {
public:
    bool isValid(const string& s) {
        std::stack<char> open;
        for (size_t i=0; i<s.size(); ++i){
            switch (s[i]){
                case ']':
                    if (!open.size() || open.top() != '[') return false;
                    break;
                case ')':
                    if (!open.size() || open.top() != '(') return false;
                    break;
                case '}':
                    if (!open.size() || open.top() != '{') return false;
                    break;
                default:
                    open.push(s[i]);
                    continue;
                    break;
            }
            open.pop();
        }
        return open.empty();
    }
};
