using namespace std;
#include <stack>
#include <iostream>
#include <algorithm>

int forest[505][505];
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dp[505][505];


int dfs(int x, int y){
    if (dp[x][y] != 0) return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) {
            continue;
        }
        if (forest[nx][ny] <= forest[x][y]) {
            continue;
        }
        dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }
    return dp[x][y];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> forest[i][j];
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
