#include <string>

int Convert(char c){
    switch(c){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return -1;
}



class Solution {
public:
    int romanToInt(const std::string& s) {
        short sum = 0;
        for(size_t i=0; i<s.size()-1; ++i){
            if (Convert(s[i]) < Convert(s[i+1])){
                sum -= Convert(s[i]);
            } else {
                sum += Convert(s[i]);
            }
        }
        sum += Convert(s[s.size()-1]);
        return sum;
    }
};