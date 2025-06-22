class Solution {
public:
bool checkBFS(unordered_map<int,vector<int>>&adj,int s, int d,vector<bool>&visited){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u==d)return true;

        for(auto &v:adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v]=true;
            }
        }
    }

    return false;
}
bool checkDFS(unordered_map<int,vector<int>>&adj,int s, int d,vector<bool>&visited){
    if(s==d)return true;
    if(visited[s]==true) return false;
    visited[s] = true;

    for(auto &node:adj[s]){
        if(checkDFS(adj,node,d,visited)==true) return true;
    }

    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adj;
        for(vector<int>edge:edges){
            int u = edge[0];
            int v = edge[1];

            // bi directional
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n,false);

        return checkBFS (adj,source, destination,visited);
    }
};