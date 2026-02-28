#include <iostream>
#include <algorithm>
using namespace std;

long long dp[505][505]; // dp[i][j]: the minimal cost to chain from "i" to "j"
int r[505];
int c[505];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r[i] >> c[i];
        dp[i][i] = 0;
    }
    
    
    
    for (int gap = 1; gap < n; gap++){
        for (int i = 0; i < n - gap; i++){
            int j = i + gap;
            dp[i][j] = 1e18;
            for (int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + (long long)r[i] * c[k] * c[j]);
            }
        }
    }
    
    cout << dp[0][n-1] << '\n';
}