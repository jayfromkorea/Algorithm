#include <iostream>
#include <stack>
#include <utility>
#include <iostream>
#define X first
#define Y second
using namespace std;

int forest[501][501];
bool vis[501][501];
int dp[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

int dfs(int i, int j);

int dfs(int i, int j){
	
	if (vis[i][j]) return dp[i][j];
	vis[i][j] = 1;
	dp[i][j] = 1;
	
	for(int p = 0; p < 4; p++){
		int nx = i + dx[p];
		int ny = j + dy[p];
		
		if (nx < 0 || nx >= n || ny < 0 || nx >= n) continue;
		if (forest[nx][ny] > forest[i][j]){
			dp[i][j] = max(dp[i][j], dfs(nx, ny) + 1);
		}
	}	
	return dp[i][j];
}

int main() {
	
	int ans = 0;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> forest[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans = max(dfs(i, j), ans);
		}
	}
	cout << ans << '\n';
}