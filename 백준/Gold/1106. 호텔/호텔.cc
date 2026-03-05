#include <iostream>
#include <algorithm>
using namespace std;

int dp[1101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int c, n;
    cin >> c >> n;
    int cost[21];
    int client[21];
    int max_cli = 0;
    for (int i = 0; i < n; i++) {
        cin >> cost[i] >> client[i];
        max_cli = max(max_cli, client[i]);
    }
    
    dp[0] = 0;
    for (int i = 1; i < c + max_cli; i++) {
        dp[i] = 1e7;
        for (int j = 0; j < n; j++){
            if (i >= client[j] && dp[i - client[j]] != 1e7) dp[i] = min(dp[i], dp[i - client[j]] + cost[j]);
        }
        
    }
    int ans = 1e7;
    for (int i = c; i < c + max_cli; i++) ans = min(ans, dp[i]);
    cout << ans << '\n';
}