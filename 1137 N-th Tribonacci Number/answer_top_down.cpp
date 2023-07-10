class Solution {
    int dp(const int n, std::unordered_map<int,int>& memo){
        if (!memo.count(n)) memo[n] = dp(n-3,memo) + dp(n-2,memo) + dp(n-1,memo);
        return memo[n];
    }
public:
    int tribonacci(const int n) {
        std::unordered_map<int,int> memo;
        memo[0] = 0;
        memo[1] = memo[2] = 1;
        return dp(n,memo);
    }
};
