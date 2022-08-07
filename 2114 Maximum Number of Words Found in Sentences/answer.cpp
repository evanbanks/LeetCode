#include <vector>
#include <string>

class Solution {
public:
    int mostWordsFound(const std::vector<std::string>& sentences) {
        int max_words = 0;
        for (const auto& s : sentences){
            int words = 0;
            bool in_word = false;
            for (size_t i=0; i<s.size(); ++i){
                if (s[i] != ' ' && !in_word){
                    ++words;
                    in_word = true;
                } else if (s[i] == ' ') in_word = false;
            }
            max_words = std::max(max_words,words);
        }
        return max_words;
    }
};