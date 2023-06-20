class Solution {
public:
    int minimumMoves(const std::string& s) {
        int min = 0;
        for (size_t i=0; i<s.size(); ++i){
            if (s[i] == 'X'){
                ++min;
                i += 2;
            }
        }
        return min;
    }
};
