#include <iostream>
#include <cstring>
using namespace std;

int main() {
	//Floyd's algorithm
	//Baekjoon 11404
	//6.12.2025
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m; // num of cities, num of buses respectively
	cin >> n >> m;
	int dis[101][101]; // costs from one city to another
	const int INF = 0x3f3f3f3f;
	memset(dis, INF, sizeof(dis));
	
	// Input
	int a, b, c; // from, to, cost
	while (m--) {
		cin >> a >> b >> c;
		dis[a][b] = min(dis[a][b], c);
	}
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	
	//Floyd's
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
	
	//Output
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (dis[i][j] == INF) cout << 0 << ' ';
			else cout << dis[i][j] << ' ';
		}
		cout << '\n';
	}
}
