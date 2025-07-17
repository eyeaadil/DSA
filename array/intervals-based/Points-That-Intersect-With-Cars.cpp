class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        ans.push_back(nums[0]);
        for(int i=0;i<n;i++){
            if(ans.back()[1] >= nums[i][0]){
                ans.back()[0] = min(ans.back()[0] , nums[i][0]);
                ans.back()[1] = max(ans.back()[1] , nums[i][1]);
            }else{
                ans.push_back(nums[i]);
            }
        }

        for(int i=0;i<ans.size();i++){
            int x1 = ans[i][0];
            int x2 = ans[i][1];
            int digit = (x2-x1) + 1;
            count+=digit;
        }
        return count;
    }
};