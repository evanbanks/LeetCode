class Solution {
public:
    int numOfSubarrays(const std::vector<int>& arr, const int k, const int threshold) {
        int num_subs = 0;
        double average = 0;
        for (int ws=0, we=0; we<arr.size(); ++we){
            average += arr[we];
            if (we >= k-1){
                if (average/k >= threshold) ++num_subs;
                average -= arr[ws++];
            }
        }
        return num_subs;
    }
};
