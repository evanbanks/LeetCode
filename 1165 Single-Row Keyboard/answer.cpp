class Solution {
public:
    int calculateTime(string& keyboard, string& word) {
        unordered_map<char,int> m;
        for (int i=0; i<keyboard.size(); ++i){
            m[keyboard[i]] = i;
        }
        int ans = 0;
        int last = 0;
        for (char c : word){
            ans += abs(last - m[c]);
            last = m[c];
        }
        return ans;
    }
};
