class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         // code here
         int V = graph.size();
        int n = V;
        vector<int>indegree(n,0);
        vector<vector<int>>adj(V);
        for(int u=0;u<V;u++){
            for(int &v : graph[u]){
                adj[v].push_back(u);
            }
        }
        
        //calculate indegree
        for(int u=0;u<n;u++){
            for(auto &v:adj[u]){
                indegree[v]++;
            }
        }
        
        queue<int>q;
        int count = 0;
        //put node in queue whose indegree is 0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;  //count ko increase kar liya
            }
        }
        
        //Apply BFS
        vector<int>isSafe(V,false);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            isSafe[u] = true;
            for(auto &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(isSafe[i] == true){
                ans.push_back(i);
            }
        }

        return ans;
    }
};