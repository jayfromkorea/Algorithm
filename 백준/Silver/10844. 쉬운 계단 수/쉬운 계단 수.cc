#include <iostream>
using namespace std;

int n;
long long dp[101][11]; // 2d array initialization

void Graph() {
    cin >> n;

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }
    dp[1][0] = 0;
}

void Solution() {
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1] % 1000000000;
            } else if (j == 9) {
                dp[i][j] = dp[i - 1][j - 1] % 1000000000;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
            }
        }
    }

    long long ans = 0; // Change the type to long long to prevent overflow
    for (int k = 0; k <= 9; k++) {
        ans = (ans + dp[n][k]) % 1000000000; // Modulo after summing
    }

    cout << ans;
}

int main() {
    Graph();
    Solution();
    return 0;
}
