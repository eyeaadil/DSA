class Solution {
public:
    bool isCycleDFS(vector<vector<int>> &adj,vector<int>&visited,int u,vector<int> &inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        
        for(auto &v:adj[u]){
            if(!visited[v]){
                if(isCycleDFS(adj,visited,v,inRecursion)){
                    return true;
                }
            }else if(inRecursion[v] == true){  //visited hai inrecursion me bhi hai 
                                                // then cycle present hai
                return true;
            }
        }
        
        inRecursion[u] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int n = graph.size();
     
        vector<int>visited(n,false);
        vector<int>inRecursion(n,false);
    
         for(int i=0;i<n;i++){
             if(!visited[i]){
                isCycleDFS(graph,visited,i,inRecursion);
             }
         }
         

         vector<int>ans;
         for(int i=0;i<n;i++){
            if(inRecursion[i] == false){
                ans.push_back(i);
            }
         }

         return ans;
    }
};
