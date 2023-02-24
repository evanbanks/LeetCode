class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string res;
        std::reverse(s.begin(),s.end());
        for (size_t i=0; i<s.size(); ++i){
            if (s[i] != ' '){
                size_t j = i;
                while (j < s.size() && s[j] != ' ') ++j;
                std::reverse(s.begin()+i,s.begin()+j);
                res += s.substr(i,j-i) + " ";
                i = j;
            }
        }
        return res.substr(0,res.length()-1);
    }
};
