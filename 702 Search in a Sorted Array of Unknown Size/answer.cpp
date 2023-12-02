class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0, right = max(0,target - reader.get(0));
        while (left < right){
            int mid = (left + right) / 2;
            if (reader.get(mid) < target) left = mid + 1;
            else right = mid;
        }
        return reader.get(left) == target ? left : -1;
    }
};
