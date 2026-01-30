#include <iostream>
using namespace std;

int n, m;
int dp[505][505];
int board[505][505];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int x, int y){
    if (x == n - 1 && y == m - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y]; // elements of dp need to be set to -1 prior to this point
    dp[x][y] = 0; // Set the initial value to 0
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[x][y] <= board[nx][ny]) continue;
        dp[x][y] += dfs(nx, ny);
    }
    return dp[x][y];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    }
    dp[n-1][m-1] = 1;
    cout << dfs(0, 0) << '\n';
}