class Solution {
public:
    bool closeStrings(string& word1, string& word2) {
        if (word1.size() != word2.size()) return false;
        vector<int> f1(26);
        for (char c : word1) ++f1[c-97];
        vector<int> f2(26);
        for (char c : word2) ++f2[c-97];
        unordered_multiset<int> freqs;
        for (int i=0; i<f1.size(); ++i){
            if (f1[i] && !f2[i] || f2[i] && !f1[i]) return false;
            freqs.insert(f1[i]);
        }
        for (int i=0; i<f2.size(); ++i){
            if (freqs.find(f2[i]) != freqs.end()){
                freqs.erase(freqs.find(f2[i]));
            }
        }
        return freqs.empty();
    }
};
