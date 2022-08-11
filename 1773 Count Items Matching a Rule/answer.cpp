#include <vector>
#include <string>

class Solution {
public:
    int countMatches(const std::vector<std::vector<std::string>>& items, const std::string& ruleKey, const std::string& ruleValue) {
        int matches = 0;
        for (int i=0; i<items.size(); ++i){
            if (ruleKey == "type" && items[i][0] == ruleValue) ++matches;
            else if (ruleKey == "color" && items[i][1] == ruleValue) ++ matches;
            else if (ruleKey == "name" && items[i][2] == ruleValue) ++matches;
        }
        return matches;
    }
};