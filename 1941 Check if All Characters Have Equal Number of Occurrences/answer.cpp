#include<string>
#include <unordered_map>

class Solution {
public:
    bool areOccurrencesEqual(const std::string& s) {
        std::unordered_map<char,int> freq;
        for (const auto& c : s){
            ++freq[c];
        }
        int good_freq = freq.begin()->second;
        for (const auto& [key,val] : freq){
            if (val != good_freq) return false;
        }
        return true;
    }
};