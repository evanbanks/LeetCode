class Solution {
public:
    bool checkZeroOnes(const std::string& s) {
        int max_one, max_zero, curr_one, curr_zero;
        max_one = max_zero = curr_one = curr_zero = 0;
        for (int i=0; i<s.size(); ++i){
            if (s[i] == '1'){
                max_one = std::max(max_one,++curr_one);
                curr_zero = 0;
            } else {
                max_zero = std::max(max_zero,++curr_zero);
                curr_one = 0;
            }
        }
        return max_one > max_zero;
    }
};
