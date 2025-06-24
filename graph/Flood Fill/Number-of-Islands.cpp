class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(int i, int j,vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<P>que;
        que.push({i,j});
        grid[i][j] = '0';

        while(!que.empty()){
            P curr = que.front();
            que.pop();
            int x = curr.first;
            int y = curr.second;

            for(auto &dir : directions){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] == '1'){
                    que.push({nx,ny});
                    grid[nx][ny] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt= 0 ;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,grid);
                }
            }
        }

        return cnt;
    }
};