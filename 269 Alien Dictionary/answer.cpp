class Solution {
    bool bad = false;
    std::string s;
    std::unordered_set<char> visited;
    std::unordered_set<char> processed;
    std::unordered_map<char,std::vector<char>> adj;

    bool dfs(const char c){
        if (bad) return bad;
        visited.insert(c);
        for (const char a : adj[c]){
            if (!visited.count(a)){
                dfs(a);
            } else if (!processed.count(a)){
                bad = true;
            }
        }
        s.push_back(c);
        processed.insert(c);
        return bad;
    }
public:
    string alienOrder(const std::vector<std::string>& words) {
        std::unordered_set<char> alphabet;
        for (size_t i=1; i<words.size(); ++i){
            for (size_t j=0; j<words[i].size(); ++j){
                if (words[i-1][j] != words[i][j]){
                    adj[words[i-1][j]].push_back(words[i][j]);
                    break;
                }
                if (words[i-1].size() > words[i].size() && j == words[i].size()-1) return "";
            }
        }
        for (const auto& w : words){
            for (const char c : w) alphabet.insert(c);
        }
        for (const char a : alphabet){
            if (!visited.count(a) && dfs(a)) return "";
        }
        std::reverse(s.begin(),s.end());
        return s;
    }
};
