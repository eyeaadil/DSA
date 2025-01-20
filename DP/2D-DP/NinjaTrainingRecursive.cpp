#include <bits/stdc++.h>
using namespace std;

int f(int ind, int last, vector<vector<int>> &points) {
    // Base case: When we are on the first day
    if (ind == 0) {
        int maxi = 0;
        // Iterate over all tasks to find the maximum points for day 0,
        // excluding the last performed task
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    // Recursive case: For each task other than the last one,
    // calculate the maximum points
    int maxi = 0;
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int point = points[ind][task] + f(ind - 1, task, points);
            maxi = max(maxi, point);
        }
    }

    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
    // Start the recursive calculation from the last day with no previous activity (indicated by 3)
    return f(n - 1, 3, points);
}

int main() {
    // Define the point matrix
    vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};

    int n = points.size();
    cout << "Number of days: " << n << endl;

    // Calculate and print the maximum points that can be achieved
    cout << "Maximum points: " << ninjaTraining(n, points) << endl;

    return 0;
}
