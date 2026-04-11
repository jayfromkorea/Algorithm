#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int vertex, edge, k;
    int u, v, weight;
    vector<pair<int, int>> adj[20005]; // {weight, to}
    int md[20005]; // An array to store minimal distances to reach each node of indeces
    cin >> vertex >> edge >> k;
    
    for (int i = 1; i <= vertex; i++) md[i] = 1e9;
    md[k] = 0;
    
    
    // Input
    for (int i = 0; i < edge; i++){
        cin >> u >> v >> weight;
        adj[u].push_back({weight, v});
    }
    
    // Djikstra's
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, k});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int loc = cur.second; // Location
        int cost = cur.first; // Cost spent so far
        if (md[loc] != cost) continue; // If not match, skip
        for (pair<int, int> nxt : adj[loc]){
            int ncost = cost + nxt.first;
            if (ncost < md[nxt.second]) {
               md[nxt.second] = ncost; 
               pq.push({ncost, nxt.second}); // Add neighboring verteces
            } 
            
        }
    }
    
    // Output
    for (int i = 1; i <= vertex; i++) {
        if (i == k) cout << 0 << '\n';
        else if (md[i] == 1e9) cout << "INF" << '\n';
        else cout << md[i] << '\n';
    }
}