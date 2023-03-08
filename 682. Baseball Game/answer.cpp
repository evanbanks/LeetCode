class Solution {
public:
    int calPoints(const vector<string>& operations) {
        std::vector<int> scores(operations.size());
        int size = 0;
        for (const auto& o : operations){
            if (o == "D") scores[size] = scores[size-1] * 2;
            else if (o == "+") scores[size] = scores[size-1] + scores[size-2];
            else if (o == "C") size -= 2;
            else scores[size] = std::stoi(o);
            ++size;
        }
        int sum = 0;
        for (size_t i=0; i<size; ++i) sum += scores[i];
        return sum;
    }
};
