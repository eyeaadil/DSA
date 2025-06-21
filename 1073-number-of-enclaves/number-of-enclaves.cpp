class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<P>que;


        //Push all sources (boundary land cells) into the queue.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==1){
                    que.push({i,j});
                    grid[i][j] = 0;
                }
            }
        }



        //Use BFS to mark all reachable land from the boundary.
        while(!que.empty()){
            int N = que.size();

            while(N--){
                P curr = que.front();
                que.pop();
                int i = curr.first;
                int j = curr.second;


                for(auto &dir:directions){
                    int i_ = i+ dir[0];
                    int j_ = j+ dir[1];

                    if(i_>= 0 && i_<m && j_>=0 && j_<n && grid[i_][j_] == 1){
                        grid[i_][j_] = 0;
                        que.push({i_,j_});
                    }
                }

            }
        }
        // count all unvisited land cells — these are enclaves.
        int count  = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }


        return count;
    }
};