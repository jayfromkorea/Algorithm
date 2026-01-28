using namespace std;
#include <iostream>
#include <algorithm>
// Greedy Panda

int n;
int dp[505][505];
int board[505][505];
bool vis[505][505];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int p, int q){
    if (vis[p][q]) return dp[p][q];
    vis[p][q] = 1; // Marking it as visited
    dp[p][q] = 1;  // The first forest visiting
    
    for (int i = 0; i < 4; i++){
        int nx = p + dx[i];
        int ny = q + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (board[nx][ny] > board[p][q]) {
            dp[p][q] = max(dp[p][q], dfs(nx, ny) + 1);
        }
    }
    
    return dp[p][q];
    
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
	    for (int j = 0; j < n; j++){
	        cin >> board[i][j];
	    }
	}
    
    int ans = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ans = max(ans, dfs(i, j));
        }
    }
    
    cout << ans << '\n';
}
