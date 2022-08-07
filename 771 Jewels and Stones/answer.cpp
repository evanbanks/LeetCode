#include <string>
#include <unordered_set>

class Solution {
public:
    int numJewelsInStones(const std::string& jewels, const std::string& stones) {
        std::unordered_set<char> stones_that_are_jewels;
        for (const auto& c : jewels){
            stones_that_are_jewels.insert(c);
        }
        int count = 0;
        for (const auto& c : stones){
            if (stones_that_are_jewels.count(c)) ++count;
        }
        return count;
    }
};