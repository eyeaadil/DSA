class Solution {
public:
    int m,n;
    vector<vector<int>>directions {{0,1},{0,-1},{1,0},{-1,0}};
    typedef pair<int,int>P;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>>result(m,vector<int>(n,-1));
        queue<P>que;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    que.push({i,j});
                    result[i][j] = 0;
                }
            }
        }

        while(!que.empty()){
            int N = que.size();

            while(N--){
                P curr = que.front();
                int x = curr.first;
                int y = curr.second;
                que.pop();
                for(auto &dir:directions){
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if(nx>=0 && ny>= 0 && nx<m && ny<n && result[nx][ny] == -1){
                        result[nx][ny] = result[x][y] + 1;
                        que.push({nx,ny});
                    }
                }
            }
        }

        return result;

    }
};