using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 10005;
vector<int> adj[MAX];
int pop[MAX];
int dp1[10005];
int dp2[10005];

void dfs(int cur, int prev){
    dp1[cur] = pop[cur];
    dp2[cur] = 0;
    for (int nxt : adj[cur]){
        if (nxt == prev) continue;
        dfs(nxt, cur);
        dp1[cur] += dp2[nxt];
        dp2[cur] += max(dp1[nxt], dp2[nxt]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> pop[i];
    }
    int u, v;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp1[1], dp2[1]) << '\n';
}