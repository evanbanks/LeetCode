#include <vector>
#include <stack>

class Solution {
public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, const int sr, const int sc, const int color) {
        if (color == image[sr][sc]) return image;
        int old_color = image[sr][sc], rows = image.size(), cols = image[0].size();
        std::stack<std::pair<int,int>> s;
        s.push({sr,sc});
        std::vector<std::pair<int,int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        while (!s.empty()){
            std::pair<int,int> p = s.top();
            s.pop();
            image[p.first][p.second] = color;
            for (const auto& [r,c] : dirs){
                if (p.first + r >= 0 && p.first + r < rows && p.second + c >= 0 && p.second + c < cols && image[p.first+r][p.second+c] == old_color){
                    s.push({p.first+r,p.second+c});
                }
            }
        }
        return image;
    }
};