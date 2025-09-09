#include <iostream>
#define MOD 1000000000
using namespace std;

int dp[10][105];

int main() {
    int n;
    cin >> n;

    // Base case: length 1, digits 1 to 9 are allowed
    for (int i = 1; i <= 9; i++) {
        dp[i][0] = 1;
    }

    // Fill the dp table
    for (int len = 1; len < n; len++) {
        for (int digit = 0; digit <= 9; digit++) {
            if (digit > 0)
                dp[digit][len] = (dp[digit][len] + dp[digit - 1][len - 1]) % MOD;
            if (digit < 9)
                dp[digit][len] = (dp[digit][len] + dp[digit + 1][len - 1]) % MOD;
        }
    }

    // Sum all n-length stair numbers ending with digits 0 through 9
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[i][n - 1]) % MOD;
    }

    cout << ans << '\n';
}
