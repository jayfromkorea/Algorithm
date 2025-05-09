#include <iostream>
using namespace std;

long long table[1026][1026];
long long dp[1026][1026];
int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> table[i][j];
        }
    }
    
    
    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = table[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    
   
    
    for(int i = 0; i < m; i++){
    	 int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // Calculate the sum using the inclusion-exclusion principle
        long long ans = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
        cout << ans << "\n";
    }
    
    return 0;
}
