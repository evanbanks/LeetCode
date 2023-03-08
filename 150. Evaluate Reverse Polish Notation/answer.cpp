class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> nums;
        for (const auto& t : tokens){
            if (std::isdigit(t[t.size()-1])){
                nums.push(std::stoi(t));
            } else {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                switch (t[0]){
                    case '+':
                        nums.push(a+b);
                        break;
                    case '-':
                        nums.push(b-a);
                        break;
                    case '*':
                        nums.push(a*b);
                        break;
                    case '/':
                        nums.push(b/a);
                        break;
                }
            }
        }
        return nums.top();
    }
};
