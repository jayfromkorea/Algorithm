#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> adj[100005]; // {node, weight}
bool vis[100005];

pair<int, int> dfs(int cur, int cost){ // Returns the final destination node and the cost
    int mc = cost; // Maxiaml cost
    int ln = cur; // Last Node
    for (pair<int, int> nxt : adj[cur]){
        if (vis[nxt.first]) continue; // If visited, skip
        vis[nxt.first] = 1;
        auto ret = dfs(nxt.first, cost + nxt.second);
        if (ret.second > mc) {
            mc = ret.second;
            ln = ret.first;
        }
    }
    return {ln, mc};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ver;
    cin >> ver;
    
    
    int u, v, weight;
    for (int i = 1; i <= ver; i++){
        cin >> u;
        while (1){
            cin >> v;
            if (v == -1) break;
            cin >> weight;
            adj[u].push_back({v, weight});
        }
    }
    
    vis[1] = 1;
    int far = dfs(1, 0).first; // Find the farthest node from node "1"
    memset(vis, 0, sizeof(vis));
    vis[far] = 1;
    cout << dfs(far, 0).second << '\n'; // The diameter is the cost from the farthest to its farthest node
    // Print out the diameter of the tree
    
    
}