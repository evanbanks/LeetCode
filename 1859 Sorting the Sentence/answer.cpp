#include <string>
#include <unordered_map>

class Solution {
public:
    std::string sortSentence(const std::string& s) {
        std::unordered_map<int,std::string> map;
        int word_start = 0;
        for (int i=0; i<s.size(); ++i){
            if (s[i] == ' ') word_start = i+1;
            else if (isdigit(s[i])){
                map[s[i]-48] = s.substr(word_start,i-word_start);
            }
        }
        std::string result {map[1]};
        for (int i=2; i<=map.size(); ++i){
            result = result + " " + map[i];
        }
        return result;
    }
};