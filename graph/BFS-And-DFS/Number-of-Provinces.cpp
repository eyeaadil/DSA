class Solution {
public:

    void DFS(int u, unordered_map<int, vector<int>> &adj, vector<int> &visited){
        visited[u] = true;

        for(auto &v:adj[u]){
            if(!visited[v]){
                DFS(v,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count =0;

        int n = isConnected.size();
        unordered_map<int, vector<int>> adj;
        vector<int> visited(n, false);
        
        // build adjacency list from matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                DFS(i,adj,visited);
                count++;
            }
        }

        return count;
    }
};