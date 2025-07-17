class Solution {
public:
    int mod = 1e9+7;
    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size();
        sort(ranges.begin(),ranges.end());
        int count = 0;
        vector<vector<int>>result;
        result.push_back(ranges[0]);
        for(int i=0;i<n;i++){
            if(result.back()[1] >= ranges[i][0]){
                count = (count+1)%mod;
                result.back()[0] = min(result.back()[0],ranges[i][0]);
                result.back()[1] = max(result.back()[1],ranges[i][1]);
            }else{
                result.push_back(ranges[i]);
            }
        }

          // Return 2^k % mod

          int k = result.size();
        long long ways = 1;
        for (int i = 0; i < k; i++) {
            ways = (ways * 2) % mod;
        }


        return ways;
    }
};