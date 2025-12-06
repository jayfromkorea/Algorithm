#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int nxt[101][101];

int main() {
	//Floyd's algorithm
	//Baekjoon 11780
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
		if(dis[a][b] > c) {
			dis[a][b] = c;
			nxt[a][b] = b;
		}
	}
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	
	//Floyd's
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (dis[i][k] + dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
					nxt[i][j] = nxt[i][k];
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
	
	int u;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			vector<int> path; // A vector to store interconnecting cities
			if (dis[i][j] == INF || dis[i][j] == 0){  // if it has no path or it itself
				cout << "0\n";
				continue; // skip
			}
			
			u = i;
			path.push_back(u);
			while (u != j) {
				path.push_back(nxt[u][j]);
				u = nxt[u][j];
			}
			cout << path.size() << ' '; // Print the num of inter connecting cities
			for (int city : path) cout << city << ' '; // Print the path
			cout << '\n';
		}
		
	}
	
}