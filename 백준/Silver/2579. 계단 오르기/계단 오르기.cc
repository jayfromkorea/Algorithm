#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int stairs[301]; // 계단 점수
    long dp[301] = {0}; // dp 배열 초기화

    for (int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }

    dp[1] = stairs[1];
    
    if (n >= 2) {
        dp[2] = stairs[1] + stairs[2];
    }
    
    if (n >= 3) {
        dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
    }

    for (int i = 4; i <= n; i++) {
        dp[i] = stairs[i] + max(dp[i - 2], dp[i - 3] + stairs[i - 1]);
    }

    cout << dp[n] << endl; // 최종 점수 출력
    return 0;
}
