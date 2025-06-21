class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        queue<P>que;
        vector<vector<int>> height(m,vector<int>(n,-1));


        //height of eater cell must be 0
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(isWater[i][j] == 1){
                    height[i][j] = 0;
                    que.push({i,j}); // this is source

                }
            }
        }



        //khandani template of multi source BFS
         while(!que.empty()){
            int N = que.size();

            while(N--){
                P curr = que.front();
                que.pop();
                int i = curr.first;
                int j = curr.second;

                for(auto &dir:directions){
                    int i_ = i+dir[0];
                    int j_ = j+dir[1];

                    if(i_>=0 && i_< m && j_>=0 &&j_< n && height[i_][j_] == -1){
                        height[i_][j_] = height[i][j]+1;
                        que.push({i_,j_});
                    }
                }
            }
         }

         return height;
    }
};