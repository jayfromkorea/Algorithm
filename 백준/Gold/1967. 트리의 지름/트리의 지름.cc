#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<pair<int,int>> adj[10005];
bool vis[10005];

pair<int,int> dfs(int cur, int sum){
    vis[cur] = 1;
    pair<int,int> ret = {sum, cur};

    for (auto [nxt, w] : adj[cur]){
        if (vis[nxt]) continue;
        ret = max(ret, dfs(nxt, sum + w));
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int u, v, w;
    for (int i = 0; i < n - 1; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    memset(vis, 0, sizeof(vis));
    auto [_, A] = dfs(1, 0);

    memset(vis, 0, sizeof(vis));
    auto [ans, B] = dfs(A, 0);

    cout << ans << '\n';
}