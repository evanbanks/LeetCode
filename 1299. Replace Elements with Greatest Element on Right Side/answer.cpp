class Solution {
public:
    std::vector<int> replaceElements(std::vector<int>& arr) {
        int max = arr[arr.size()-1];
        for (int i=arr.size()-1; i>=0; --i){
            int val = arr[i];
            arr[i] = max;
            max = std::max(val,max);
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
};
