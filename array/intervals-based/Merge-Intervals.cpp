class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);

        for(int i=0;i<n;i++){
            if(intervals[i][0] <= ans.back()[1]){
                ans.back()[0] = min(ans.back()[0],intervals[i][0]);
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};