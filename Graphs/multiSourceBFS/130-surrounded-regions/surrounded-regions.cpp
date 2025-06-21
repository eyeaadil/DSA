class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<P> que;
        vector<vector<int>> isVisited(n, vector<int>(m, 0));

        //  Multi-source - Push all boundary 'O's into queue
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O') {
                    que.push({i, j});
                    isVisited[i][j] = 1;
                }
            }
        }

        //  Khandani BFS
        while (!que.empty()) {
            int N = que.size();
            while (N--) {
                P curr = que.front(); que.pop();
                int i = curr.first;
                int j = curr.second;

                for (auto& dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m
                        && board[i_][j_] == 'O' && isVisited[i_][j_] == 0) {
                        que.push({i_, j_});
                        isVisited[i_][j_] = 1;
                    }
                }
            }
        }

     // Flip all unvisited 'O's to 'X'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O' && isVisited[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
