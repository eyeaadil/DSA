class Solution {
public:
    void DFS(unordered_map<int,vector<int>>&adj,int i,vector<int>& informTime, int &ans,int curr){
        curr+=informTime[i];
        ans = max(ans,curr);

        for(auto &v : adj[i]){
            DFS(adj,v,informTime,ans,curr);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            if(manager[i] != -1){
                adj[manager[i]].push_back(i); 
            }
        }
        int ans=0, curr = 0;
        DFS(adj,headID,informTime,ans,curr);

        return ans;
    }
};