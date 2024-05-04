#include <bits/stdc++.h>
using namespace std;
 

// Function to find the Eulerian path using a stack-based DFS approach
void findEulerianPath(int startNode, unordered_map<int, vector<int>>& graph, vector<int>& result) {
    stack<int> stack;
    stack.push(startNode);

    while (!stack.empty()) {
        int node = stack.top();

        if (graph[node].empty()) { // No more outgoing edges
            stack.pop();
            result.push_back(node); // Add node to the result
        } else {
            int nextNode = graph[node].back(); // Take the last outgoing edge
            graph[node].pop_back(); // Remove the edge from the graph
            stack.push(nextNode); // Move to the next node
        }
    }
}

// Function to get a valid arrangement of pairs
vector<pair<int, int>> validArrangement(const vector<pair<int, int>>& pairs) {
    unordered_map<int, vector<int>> graph; // Graph representation
    unordered_map<int, int> inDegrees, outDegrees; // Track in-degrees and out-degrees

    // Build the graph and compute in-degrees/out-degrees
    for (const auto& p : pairs) {
        int u = p.first;
        int v = p.second;

        graph[u].push_back(v); // Create an edge from u to v
        outDegrees[u]++; // Increment out-degree for u
        inDegrees[v]++; // Increment in-degree for v
    }

    // Find a suitable start node for the Eulerian path
    int startNode = -1;
    for (const auto& node : outDegrees) {
        int inDegree = inDegrees[node.first];

        if (node.second - inDegree == 1) { // Node with one more out-degree
            startNode = node.first; // Likely starting point for the path
        } else if (node.second == inDegree && startNode == -1) { // Equal in and out-degrees
            startNode = node.first; // Can be a valid start node
        }
    }

    if (startNode == -1) {
        // If no specific start node, use the first node in the pairs
        startNode = pairs[0].first;
    }

    vector<int> path; // To store the Eulerian path
    findEulerianPath(startNode, graph, path);

    // Reverse the path to get the correct order for pairs
    reverse(path.begin(), path.end());

    // Create the list of pairs based on the path
    vector<pair<int, int>> result;
    for (size_t i = 1; i < path.size(); i++) {
        result.push_back({path[i - 1], path[i]});
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("../output/output.txt");
    int n;
    cin>>n;
    vector<pair<int,int>> pairs(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        pairs.push_back({x,y});
    }
    vector<pair<int,int>> re= validArrangement(pairs);
    if(re.size()==n){
        for (auto& p : re) {
        cout << "(" << p.first << ", " << p.second << ")" << " ";
    }
    }
    else{
        cout<<"No valid arrangment possible";

    }
    

    return 0;  
}