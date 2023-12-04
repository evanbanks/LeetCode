class Solution {
public:
    string largestGoodInteger(string& num) {
        string ans;
        for (int i=0, j=0; j<num.size(); ++j){
            if (num[i] != num[j]) i = j;
            else if (j - i == 2 && (!ans.size() || ans[0] < num[i])){
                ans = num.substr(i,3);
            }
        }
        return ans;
    }
};
