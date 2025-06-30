class Solution {
public:

     vector<int> getNSL(const vector<int>& nums, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> getNSR(const vector<int>& nums, int n) {
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = INT_MIN;
        vector<int>L = getNSL(heights,n);
        vector<int>R = getNSR(heights,n);
        for(int i=0;i<n;i++){
            int left = i - L[i];
            int right = R[i] - i;
           int width = R[i] - L[i] - 1;

            int area = heights[i] * width;
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};