class Solution {
public:
    int maxArea(const std::vector<int>& height) {
        int l = 0, r = height.size()-1;
        int max_area = 0;
        while (l<r){
            int area = std::min(height[l],height[r])*(r-l); 
            max_area = std::max(area,max_area);
            if (height[l] < height[r]){
                ++l;
            } else {
                --r;
            }
        }
        return max_area;
    }
};
