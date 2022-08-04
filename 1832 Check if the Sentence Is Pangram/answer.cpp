#include <string>
#include <unordered_set>

class Solution {
public:
    bool checkIfPangram(const std::string& sentence) {
        std::unordered_set<char> alphabet;
        for (const auto& s : sentence){
            alphabet.insert(s);
        }
        return alphabet.size() == 26;
    }
};