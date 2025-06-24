class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int BFS(int i,int j,vector<vector<int>>& grid ){
        int m = grid.size();
        int n = grid[0].size();
        queue<P>que;
        que.push({i,j});
        grid[i][j] = 0;
        int area = 1;
        while(!que.empty()){
            P curr = que.front();
            que.pop();
            int x = curr.first;
            int y = curr.second;
             for(auto &dir : directions){
                int nx = x + dir[0];
                int ny = y + dir[1];
                 if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] == 1){
                    area++;
                    que.push({nx,ny});
                    grid[nx][ny] = 0;
                 }
             }
        }

        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int area = BFS(i,j,grid);
                    maxArea = max(maxArea,area);
                }
            }
        }

        return maxArea;
    }
};