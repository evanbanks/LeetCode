#include <vector>
#include <string>

class Solution {
public:
    int finalValueAfterOperations(const std::vector<std::string>& o) {
        int sum=0;
        for (int i=0; i<o.size(); ++i){
            if (o[i][1] == '+') ++sum;
            else --sum;
        }
        return sum;
    }
};