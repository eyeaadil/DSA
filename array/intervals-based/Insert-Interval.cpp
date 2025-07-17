class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());

        vector<vector<int>>result;
        result.push_back(intervals[0]);

        for(int i=0;i<intervals.size();i++){
            if(result.back()[1]>=intervals[i][0]){
                result.back()[0] = min(result.back()[0],intervals[i][0]);
                result.back()[1] = max(result.back()[1],intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};