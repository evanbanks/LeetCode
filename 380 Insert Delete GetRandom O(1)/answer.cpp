class RandomizedSet {
    vector<int> v;
    unordered_map<int,int> idxs;
    random_device rd;
    mt19937 gen;
public:
    RandomizedSet() : gen(rd()) {

    }

    bool insert(int val) {
        if (idxs.count(val)) return false;
        v.push_back(val);
        idxs.insert({val,v.size()-1});
        return true;
    }

    bool remove(int val) {
        if (!idxs.count(val)) return false;
        int idx = idxs[val];
        v[idx] = v.back();
        v.pop_back();
        idxs[v[idx]] = idx;
        idxs.erase(val);
        return true;
    }

    int getRandom() {
        uniform_int_distribution<> dist(0,v.size()-1);
        return v[dist(gen)];
    }
};
