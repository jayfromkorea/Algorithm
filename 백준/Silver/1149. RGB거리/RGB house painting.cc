#include <iostream>
using namespace std;

int dp[1001][3];

int main() {
	int n;
	int rgb[1001][3];
	
	cin >> n;
	//Input
	for(int i = 0; i < n; i++){
		for (int j = 0; j < 3; j++){
			cin >> rgb[i][j];
		}
	}
	
	//Initialzing values
	for (int j = 0; j < 3; j++) dp[0][j] = rgb[0][j];
	//DP
	for(int i = 1; i < n; i++){
		for (int j = 0; j < 3; j++){
			if (j == 0) dp[i][j] = min(dp[i-1][j + 1], dp[i-1][j + 2]) + rgb[i][j];
			if (j == 1) dp[i][j] = min(dp[i-1][j - 1], dp[i-1][j + 1]) + rgb[i][j];
			if (j == 2) dp[i][j] = min(dp[i-1][j - 2], dp[i-1][j - 1]) + rgb[i][j];
		}
	}
	
	int ans = min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
	cout << ans << '\n';
}

