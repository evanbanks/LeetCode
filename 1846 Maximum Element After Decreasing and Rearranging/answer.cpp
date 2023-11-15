class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        vector<int> freq(arr.size());
        for (int i : arr) ++freq[min(i-1,(int)arr.size()-1)];
        int max = 0;
        for (int i=0; i<freq.size(); ++i){
            if (!freq[i]) continue;
            if (i+1 > max){
                int diff = min(i+1 - max,freq[i]);
                max += diff-1;
            }
            ++max;
        }
        return max;
    }
};
