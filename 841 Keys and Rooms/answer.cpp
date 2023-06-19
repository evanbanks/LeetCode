class Solution {
public:
    bool canVisitAllRooms(const std::vector<std::vector<int>>& rooms) {
        std::unordered_set<int> visited;
        std::stack<int> s;
        s.push(0);
        visited.insert(0);
        while(s.size()){
            int t = s.top();
            s.pop();
            for (const int r : rooms[t]){
                if (visited.find(r) == visited.end()){
                    visited.insert(r);
                    s.push(r);
                }
            }
        }
        return visited.size() == rooms.size();   
    }
};
