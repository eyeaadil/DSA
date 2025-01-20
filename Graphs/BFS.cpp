#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
    vector<int> visited(n, 0); // Initialize visited array with all 0s
    visited[0] = 1; // Mark the starting node as visited
    queue<int> q;
    q.push(0); // Push the initial starting node in the queue
    vector<int> bfs;

    // Iterate until the queue is empty
    while (!q.empty()) {
        // Get the topmost element of the queue
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        // Traverse all neighbors of the current node
        for (auto id : adj[node]) {
            // If the neighbor has not been visited yet
            if (!visited[id]) {
                visited[id] = 1; // Mark the neighbor as visited
                q.push(id);
            }
        }
    }

    return bfs;
}

int main() {
    // Example usage
    int n = 4;
    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    vector<int> result = bfsTraversal(n, adj);
    cout << "BFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
