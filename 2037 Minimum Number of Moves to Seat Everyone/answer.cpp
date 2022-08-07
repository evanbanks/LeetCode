#include <vector>
#include <algorithm>

class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
        std::sort(seats.begin(),seats.end());
        std::sort(students.begin(),students.end());
        int count = 0;
        for (size_t i=0; i<students.size(); ++i){
            count += std::abs(students[i]-seats[i]);
        }
        return count;
    }
};