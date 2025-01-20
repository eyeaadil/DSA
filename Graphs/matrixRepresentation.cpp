#include <iostream>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    int adj[n+1][m+1];

    // resprsenting m lines of edges  
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    return 0;

}