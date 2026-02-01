#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100005; 
vector<int> adj[MAX];
int dp[MAX];

int dfs(int cur, int prev){
    dp[cur] = 1;
    for (int nxt : adj[cur]){
        if (nxt == prev) continue;
        dp[cur] += dfs(nxt, cur);
    }
    return dp[cur];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, r, q;
    cin >> n >> r >> q;
    
    for (int i = 1; i <= n; i++) dp[i] = -1;
    
    int u, v;
    for (int i = 0; i < n-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(r, -1);
    
    while (q--){
        int root;
        cin >> root;
        cout << dp[root] << '\n';
    }
}