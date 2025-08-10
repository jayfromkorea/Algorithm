#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; // 충분히 큰 수 (100,000보다 크면 됨)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 비용 배열 초기화
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0; // 자기 자신으로 가는 비용 0
    }

    // 간선 정보 입력
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--; // 0-based 인덱스
        if (dist[a][b] > c) {
            dist[a][b] = c; // 여러 간선 중 최소 비용 저장
        }
    }

    // 플로이드-워셜 알고리즘
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            // 중간에 k가 포함된 경로를 고려
            if (dist[i][k] == INF) continue; // 불필요한 계산 방지
            for (int j = 0; j < n; j++) {
                if (dist[k][j] == INF) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << 0 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
