class Solution {
public:
    double average(const vector<int>& salary) {
        return 1.0*std::accumulate(salary.begin(),salary.end(),0-*std::min_element(salary.begin(),salary.end())-*std::max_element(salary.begin(),salary.end()))/(salary.size()-2);
    }
};
