#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int cost[N][3];
    for (int i = 0; i < N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    // DP 테이블 초기화
    int dp[N][3];
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    // DP 계산
    for (int i = 1; i < N; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }

    // 결과는 마지막 집을 칠하는 세 가지 색 중 최소 비용
    cout << min({dp[N-1][0], dp[N-1][1], dp[N-1][2]}) << endl;

    return 0;
}
