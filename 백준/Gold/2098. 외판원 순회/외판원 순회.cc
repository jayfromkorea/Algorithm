#include <iostream>
#include <algorithm>
using namespace std;

int dp[17][1 << 16]; //The minimal cost of travelling the cities marked in the mask with the current location of “i”

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int matrix[17][17];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    
    // Initialization
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (1 << n); j++){
            dp[i][j] = 1e9;
        }
    }
    dp[0][1] = 0; // Starts from the first city (doesn't matter which city it starts from as it's a cycle)
    
    for (int mask = 1; mask < (1 << n); mask++){
        for (int cur = 0; cur < n; cur++){
            if (!((1 << cur) & mask)) continue; // When cur is not within the mask scope
            if (dp[cur][mask] == 1e9) continue; // When there is no connected route to cur with the corresponding mask
            for (int nxt = 0; nxt < n; nxt++){
                if ((1 << nxt) & mask) continue; // When it's already visited
                if (matrix[cur][nxt] == 0) continue; // When there is no path from cur to nxt
                dp[nxt][mask | (1 << nxt)] = min(dp[nxt][mask | (1 << nxt)], dp[cur][mask] + matrix[cur][nxt]);
            }
        }
    }
    int ans = 1e9;
    for (int cur = 1; cur < n; cur++) {
        if (matrix[cur][0] != 0) ans = min(ans, dp[cur][(1 << n) - 1] + matrix[cur][0]);
    }
    
    cout << ans << '\n';
}