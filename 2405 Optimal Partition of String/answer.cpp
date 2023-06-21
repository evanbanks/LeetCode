class Solution {
public:
    int partitionString(const std::string& s) {
        int partitions = 1;
        bool seen[26] {};
        for (size_t i=0; i<s.size(); ++i){
            if (seen[s[i]-97]){
                ++partitions;
                std::memset(seen,0,26);
            }
            seen[s[i]-97] = true;
        }
        return partitions;
    }
};
