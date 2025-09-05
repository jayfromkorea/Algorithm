#include <iostream>
using namespace std;

int dp[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, st, end;
    cin >> n >> m;

    dp[0] = 0;  // prefix sum base
    for (int i = 1; i <= n; i++) {
        cin >> a;
        dp[i] = dp[i-1] + a;
    }

    while (m--) {
        cin >> st >> end;
        cout << dp[end] - dp[st-1] << '\n';
    }
}
