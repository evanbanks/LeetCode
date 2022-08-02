class Solution {
public:
    int countOdds(const int low, const int high) {
        int count=high-low+1;
        if(!(count%2)){
            return count/2;
        }
        else if(!(low%2) && !(high%2)){
            return count/2;
        } else {
            return count/2+1;
        }
        return count;   
    }
};