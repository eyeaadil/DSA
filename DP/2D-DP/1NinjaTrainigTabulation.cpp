#include <bits/stdc++.h>
using namespace std;



int main() {
    // Define the point matrix
    vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};

    int n = points.size();
    cout << "Number of days: " << n << endl;

    // Calculate and print the maximum points that can be achieved
    // cout << "Maximum points: " << ninjaTraining(n, points) << endl;
      vector<vector<int>> dp(n, vector<int>(4, -1));
      for(int day = 0;day<n;day++){
        for(int last =0;last<4;last++){
            for(int task = 0;task<=2;task++){
                if(task!=last){
                    dp[day][last] = max(dp[day-1][task],points[day][task]);
                }
            }
        }
      }

    return dp[n-1][3];
}
