class Solution {
public:
    int maxPower(const std::string& s) {
        int max_power = 0;
        for (int ws=0, we=0; we<s.size(); ++we){
            if (s[we] != s[ws]) ws = we;
            max_power = std::max(max_power,we-ws+1);
        }
        return max_power;
    }
};
