#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> sqr(n, vector<int>(n, 0));  // Initialize triangle (2D vector)

    // Read input triangle values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> sqr[i][j];
        }
    }

    // DP array to store the maximum sum at each position
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Initialize the last row of dp with the values from the triangle
    for (int i = 0; i < n; i++) {
        dp[n - 1][i] = sqr[n - 1][i];
    }

    // Fill the dp table from bottom to top
    for (int row = n - 2; row >= 0; row--) {
        for (int col = 0; col <= row; col++) {
            // The maximum sum at this position is the value at this position plus
            // the maximum of the two adjacent positions below it
            dp[row][col] = sqr[row][col] + max(dp[row + 1][col], dp[row + 1][col + 1]);
        }
    }

    // The result is stored at the top of the triangle
    cout << dp[0][0] << endl;

    return 0;
}
