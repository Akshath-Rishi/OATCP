#include <bits/stdc++.h>
using namespace std;
 

bool bfs(vector<vector<int>> rGraph, int s, int t, int parent[],int V)
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}
int fordFulkerson(vector<vector<int>> graph, int s, int t,int V)
{
    int u, v;
    vector<vector<int>>rGraph (V,vector<int>(V)); 
    for (u = 1; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
 
    int parent[V]; 
 
    int max_flow = 0; 
    while (bfs(rGraph, s, t, parent,V)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("../output/output.txt");
    int n;
    cin>>n;
    int s,d;
    cin>>s>>d;
    
    std::vector<std::vector<int>> graph(n+1, std::vector<int>(n+1, 0));
    int u,v,w;
  while (cin>>u>>v>>w) {
        graph[u][v] = w; // Set capacity for the edge
    }
    int re=fordFulkerson(graph,s,d,n+1);
    cout << re << endl;

    return 0;  
}