using namespace std;
#include <vector>
#include <iostream>
#include <algorithm>

int cost[1005];
int dp[1005];
vector<int> adj[1005];

int func(int cur){
    if (dp[cur] != -1) return dp[cur];
    for (int e : adj[cur]) dp[cur] = max(dp[cur], func(e));
    return dp[cur] = dp[cur] + cost[cur];
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t, n, k;
	cin >> t;
	while (t--){
	    cin >> n >> k;
	    fill(dp, dp + n + 1, -1);
	    for (int i = 1; i <= n; i++) adj[i].clear();
	    for (int i = 1; i <= n; i++) cin >> cost[i];
	    int u, v;
	    for (int i = 0; i < k; i++){
	        cin >> u >> v;
	        adj[v].push_back(u);
	    }
	    for (int i = 1; i <= n; i++) if (adj[i].empty()) dp[i] = cost[i];
	    int target;
	    cin >> target;
	    
	    cout << func(target) << '\n';
	}
	
	
	return 0;
}