class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int lasers = 0;
        for (int i=0; i<bank.size(); ++i){
            int l2 = 0;
            for (char c : bank[i]) if (c == '1') ++l2;
            ans += lasers * l2;
            if (l2) lasers = l2;
        }
        return ans;
    }
};
