struct thing {
    bool operator()(const pair<int,string>& p1, const pair<int,string>& p2){
        if (p1.first == p2.first){
            return p1.second > p2.second;
        }
        return p1.first < p2.first;
    }
};

class FoodRatings {
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,thing>> m;
    unordered_map<string,string> cuisine;
    unordered_map<string,int> rating;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i=0; i<foods.size(); ++i){
            m[cuisines[i]].push({ratings[i],foods[i]});
            cuisine[foods[i]] = cuisines[i];
            rating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        m[cuisine[food]].push({newRating,food});
        rating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto t = m[cuisine].top();
        while (t.first != rating[t.second]){
            m[cuisine].pop();
            t = m[cuisine].top();
        }
        return t.second;
    }
};
