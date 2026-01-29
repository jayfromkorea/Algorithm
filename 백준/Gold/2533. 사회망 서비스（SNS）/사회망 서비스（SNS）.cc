using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 1000005;
vector<int> adj[MAX];
int dp1[MAX];
int dp2[MAX];
int n;

void dfs(int cur, int prev){
    dp1[cur] = 1;
    dp2[cur] = 0;
    for (int nxt : adj[cur]){
        if (nxt == prev) continue;
        dfs(nxt, cur);
        dp1[cur] += min(dp1[nxt], dp2[nxt]);
        dp2[cur] += dp1[nxt];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int u, v;
    for (int i = 0; i < n-1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    cout << min(dp1[1], dp2[1]) << '\n';
}