#include <iostream>
#include <algorithm>
using namespace std;

// The max number of staircase numbers
int dp[105][10][1024]; // [length][last_digit][bitmask]

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    // DP Initialization
    for (int i = 1; i <= 9; i++) dp[1][i][1 << i] = 1;
    
    for (int len = 2; len <= n; len++){
        for (int d = 0; d <= 9; d++){
            for (int mask = 0; mask < 1024; mask++){
                // If 0, there is no state with the mask
                // Other wise, at least one state exists
                if (dp[len-1][d][mask] == 0) continue; 
                if (d - 1 >= 0) dp[len][d-1][mask | (1 << (d-1))] = (dp[len][d-1][mask | (1 << (d-1))] + dp[len-1][d][mask]) % 1000000000;
                if (d + 1 <= 9) dp[len][d+1][mask | (1 << (d+1))] = (dp[len][d+1][mask | (1 << (d+1))] + dp[len-1][d][mask]) % 1000000000;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i <= 9; i++){
        ans = (ans + dp[n][i][1023]) % 1000000000;
    }
    
    cout << ans << '\n';
}