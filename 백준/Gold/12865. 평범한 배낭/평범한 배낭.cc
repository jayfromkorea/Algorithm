#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001]; // dp[i][w] = max value using first i items with capacity w

int main() {
    int W[101]; // weights
    int V[101]; // values
    int n, k;

    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> W[i] >> V[i];

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= k; w++) {
            if (W[i] <= w)
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - W[i]] + V[i]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << dp[n][k] << '\n';
}
