class Solution {
public:
    int minimumLength(string& s) {
        int left = 0, right = s.size()-1;
        while (left < right && s[left] == s[right]){
            while (left < right && s[left] == s[left+1]) ++left;
            while (left < right && s[right] == s[right-1]) --right;
            ++left; --right;
        }
        return max(0,right-left+1);
    }
};
