#include <vector>

class Solution {
public:
    double average(const std::vector<int>& salary) {
        double sum = 0;
        int max = 0;
        int min = __INT32_MAX__;
        for (size_t i=0; i<salary.size(); ++i){
            sum += salary[i];
            max = std::max(max, salary[i]);
            min = std::min(min, salary[i]);
        }
        sum -= max + min;
        sum /= (salary.size() - 2);
        return sum;
    }
};