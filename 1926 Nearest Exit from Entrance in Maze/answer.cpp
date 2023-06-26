class Solution {
public:
    int nearestExit(std::vector<std::vector<char>>& maze, const std::vector<int>& entrance) {
        size_t n = maze.size(), m = maze[0].size();
        int os[4] = {1,-1,0,0};
        std::queue<std::pair<int,int>> q;

        auto is_valid = [&](unsigned i, unsigned j) -> bool {return i<n && j<m && maze[i][j] == '.';};

        auto is_exit = [&](int i, int j) -> bool {return !i || !j || i == n-1 || j == m-1;};

        int dist = 1;

        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        while (q.size()){
            size_t sz = q.size();
            for (size_t a=0; a<sz; ++a){
                auto [i,j] = q.front();
                q.pop();
                for (int k=0; k<4; ++k){
                    if (is_valid(i+os[k],j+os[3-k])){
                        if (is_exit(i+os[k],j+os[3-k])){
                            return dist;
                        }
                        q.push({i+os[k],j+os[3-k]});
                        maze[i+os[k]][j+os[3-k]] = '+';
                    }
                }
            }
            ++dist;
        }
        return -1;
    }
};
