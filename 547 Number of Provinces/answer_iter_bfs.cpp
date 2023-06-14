class Solution {
public:
    int findCircleNum(const std::vector<std::vector<int>>& isConnected) {
        std::unordered_set<int> visited;
        int num_comp = 0;
        for (size_t i=0; i<isConnected.size(); ++i){
            if (visited.find(i) == visited.end()){
                ++num_comp;
                std::queue<int> q;
                q.push(i);
                visited.insert(i);
                while(q.size()){
                    int f = q.front();
                    q.pop();
                    for (size_t j=0; j<isConnected.size(); ++j){
                        if (isConnected[f][j] && visited.find(j) == visited.end()){
                            visited.insert(j);
                            q.push(j);
                        }
                    }
                }
            }
        }
        return num_comp;
    }
};
