#include <iostream>
#include <algorithm>
using namespace std;

int dp[16];
int T[16];
int P[16];
int n;

void Input(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> T[i] >> P[i];
    }
}

void Solution(){
    for (int i = n; i >= 1; i--) { 
        if (i + T[i] <= n + 1) { 
            dp[i] = max(dp[i], P[i] + dp[i + T[i]]);
        }
        dp[i] = max(dp[i], dp[i + 1]);
    }
}

int main() {
    Input();
    Solution();
    cout << dp[1] << endl;
}
