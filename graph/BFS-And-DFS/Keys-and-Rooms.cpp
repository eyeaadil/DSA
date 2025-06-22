class Solution {
public:

    void DFS(int u,vector<vector<int>>& rooms, vector<int>&visited){
        visited[u] = true;
        for(auto & v : rooms[u]){
            if(!visited[v]){
                DFS(v,rooms,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int>visited(n,false);
        DFS(0,rooms,visited);

        for(int i=0;i<n;i++){
            if(visited[i] == false){
                return false;
            }
        }


        return true;
    }
};