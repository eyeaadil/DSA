class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();
        int oldColor = image[sr][sc];
        if (oldColor == color) return image;
    
        queue<P>que;
        image[sr][sc] = color;
        que.push({sr,sc});

        while(!que.empty()){
            P curr = que.front();
            int i = curr.first;
            int j = curr.second;
            que.pop();

            for( auto &dir : directions){
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if(i_>=0 && i_< m && j_>=0 && j_< n && image[i_][j_] == oldColor){
                    image[i_][j_] = color;
                    que.push({i_,j_});
                }

            }
        }


        return image;

    }
};