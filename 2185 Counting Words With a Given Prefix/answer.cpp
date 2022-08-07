#include <string>
#include <vector>

class Solution {
public:
    int prefixCount(const std::vector<std::string>& words, const std::string& pref) {
        int count = 0;
        for (const auto& w : words){
            if (w.substr(0,pref.size()) == pref) ++count;
        }
        return count;
    }
};