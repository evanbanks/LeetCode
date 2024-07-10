class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ops = 0;
        for (auto& s : logs){
            if (s[1] == '.') ops = max(0,ops-1);
            else if (s[0] != '.') ++ops;
        }
        return ops;
    }
};
