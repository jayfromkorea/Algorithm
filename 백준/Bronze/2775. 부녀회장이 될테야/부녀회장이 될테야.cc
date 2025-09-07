#include <iostream>
using namespace std;

int dp[15][15];

int main() {
	int t, k, n;
	
	//The ground floor 
	for (int i = 1; i <= 14; i++){
		dp[0][i] = i;
	}
	
	cin >> t;
	
	while (t--){
		cin >> k >> n;
		
		for(int i = 1; i <= k; i++){
			for (int j = 1; j <= n; j++){
				dp[i][j] = dp[i][j-1] + dp[i-1][j];
				//cout << dp[i][j] << '\n';
			}
		}
		
		cout << dp[k][n] << '\n';
	}
}