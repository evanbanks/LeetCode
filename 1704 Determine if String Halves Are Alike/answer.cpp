class Solution {
public:
    bool halvesAreAlike(string& s) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        int count = 0;
        for (int i=0; i<s.size()/2; ++i){
            if (vowels.count(tolower(s[i]))) ++count;
        }
        for (int i=s.size()/2; i<s.size(); ++i){
            if (vowels.count(tolower(s[i]))) --count;
        }
        return !count;
    }
};
