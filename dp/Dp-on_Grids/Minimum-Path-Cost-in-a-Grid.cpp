class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp, int m, int n) {
        if (i == m-1) return grid[i][j];  

        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for (int k = 0; k < n; k++) {
            int cost = grid[i][j] + moveCost[grid[i][j]][k] + f(i+1, k, grid, moveCost, dp, m, n);
            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, f(0, j, grid, moveCost, dp, m, n));
        }

        return ans;
    }
};
