class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        for (int i=0; i<dist.size(); ++i){
            dist[i] = ceil(1.0 * dist[i] / speed[i]);
        }
        sort(dist.begin(),dist.end());
        int ans = 0;
        for (int i=0; i<dist.size(); ++i){
            if (dist[i] <= i) break;
            ++ans;
        }
        return ans;
    }
};
