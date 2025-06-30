class Solution {
public:
     vector<int> getNSL(vector<int>& nums, int n) {
        vector<int> ans(n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> getNSR(vector<int>& nums, int n) {
        vector<int> ans(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& nums) {
         int n = nums.size();
        vector<int>NSL = getNSL(nums,n);
        vector<int>NSR = getNSR(nums,n);
        int mod = 1e9+7;
        long long sum = 0;

        for(int i=0;i<n;i++){
            long long ls = i - NSL[i];
            long long rs = NSR[i] - i;

            long long totalWays = ls * rs;
            long long totalSum = (1LL * nums[i] * totalWays) % mod;
            sum = (sum+totalSum)%mod;
        }

        return sum;
    }
};