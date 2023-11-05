class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int first = arr[0];
        int wins = 0;
        for (int i=1; i<arr.size(); ++i){
            if (first > arr[i]) ++wins;
            else {
                first = arr[i];
                wins = 1;
            }
            if (wins == k) return first;
        }
        return first;
    }
};
