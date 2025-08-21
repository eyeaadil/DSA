class Solution {
public:
    const int M = 1e9 + 7;

    int f(int ind, vector<int>& dp) {
        if (ind == 0) return 1;
        if (ind == 1) return 2;

        if (dp[ind] != -1) return dp[ind];
        long long l = f(ind - 1, dp);
        long long r = f(ind - 2, dp);
        return dp[ind] = (l + r) % M;
    }

    int countHousePlacements(int n) {
        vector<int> dp(n + 1, -1);
        long long ways = f(n, dp);

     
        ways = (ways * ways) % M;

        return (int)ways;
    }
};
