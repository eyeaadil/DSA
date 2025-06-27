class Solution {
public:
    
    typedef pair<int,int>P;
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};

    int bfs(int i,int j,vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<P>que;
        que.push({i,j});
        grid[i][j] = 1;

        bool isClosed = true;
        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            if(x == 0 || x == m-1 || y==0 || y==n-1) isClosed = false;
            for(auto &dir:directions){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx>=0 && ny >=0 && nx<m && ny<n && grid[nx][ny] ==0 ){
                    grid[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
        }

        return isClosed;

    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    if(bfs(i,j,grid)){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};