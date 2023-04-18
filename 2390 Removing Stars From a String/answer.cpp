class Solution {
public:
    std::string removeStars(const std::string& str) const {
        std::string s;
        for (size_t i=0; i<str.size(); ++i){
            if (str[i] == '*') s.pop_back();
            else s.push_back(str[i]);
        }
        return s;
    }
};
