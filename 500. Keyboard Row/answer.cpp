class Solution {
public:
    std::vector<std::string> findWords(const std::vector<std::string>& words) {
        std::vector<std::string> ans;
        for (const auto& w : words){
            const int row = rows[std::tolower(w[0])];
            bool same_row = true;
            for (size_t i=1; i<w.size(); ++i){
                if (rows[std::tolower(w[i])] != row){
                    same_row = false;
                    break;
                }
            }
            if (same_row) ans.push_back(w);
        }
        return ans;
    }
private:
    std::unordered_map<char,int> rows {{'q',0},{'w',0},{'e',0},{'r',0},{'t',0},{'y',0},{'u',0},{'i',0},{'o',0},{'p',0},{'a',1},{'s',1},{'d',1},{'f',1},{'g',1},{'h',1},{'j',1},{'k',1},{'l',1},{'z',2},{'x',2},{'c',2},{'v',2},{'b',2},{'n',2},{'m',2}};
};
