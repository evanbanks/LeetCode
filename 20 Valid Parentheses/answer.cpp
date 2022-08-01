#include <stack>
#include <string>

class Solution {
public:
  bool isValid(const std::string& s) {
    std::stack<char> open;
    for (size_t i=0; i<s.size(); ++i){
      if (s[i] == '(' || s[i] == '{' || s[i] == '['){
        open.push(s[i]);
      } else if (!open.empty()) {
        switch (s[i]) { // wish this was a 1 liner but ascii had to ruin it
          case ')':
            if (open.top() != '(') return false;
            break;
          case '}':
            if (open.top() != '{') return false;
            break;
          case ']':
            if (open.top() != '[') return false;
            break;
        }
        open.pop();
      } else {
        return false;
      }
    }
    return open.empty();
  }
};