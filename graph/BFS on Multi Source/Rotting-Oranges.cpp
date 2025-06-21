class Solution {
public:

    typedef pair<int,int> P;
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<P>que;
        int freshCount = 0;
        int minTime = 0;


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    que.push({i,j});
                }else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }


        if (freshCount==0){
            return 0;
        }

        while(!que.empty()){
            int N = que.size();

            while(N--){
                P curr = que.front();
                que.pop();
                int i = curr.first;
                int j = curr.second;

                for(auto &dir:directions){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_>=0 && i_< m && j_>=0 && j_< n && grid[i_][j_] == 1){
                        grid[i_][j_] = 2;
                        que.push({i_,j_});
                        freshCount--;
                    }
                }

            }

            minTime++;
        }


        if(freshCount==0){
            return minTime -1;
        }


        return -1;

    }
};