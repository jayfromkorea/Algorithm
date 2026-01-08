using namespace std;
#include <iostream>
#include <algorithm>

int dp[1005][1005];

int main(){
    string grid[1005];
    int n, m;
    cin >> n >> m;
    int temp;
    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }
    
    // The first row and column consist of 1s, if not "0"
    for (int i = 0; i < n; i++) dp[i][0] = grid[i][0] - '0';
    for (int i = 0; i < n; i++) dp[0][i] = grid[0][i] - '0';
    
    int ans = 0;
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (grid[i][j] != '0') dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (dp[i][j] > ans) ans = dp[i][j];
        }
    }
    cout << ans*ans << '\n';
}