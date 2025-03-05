#include <iostream>
using namespace std;

int n;
long long dp[101][11]; // 2d graph initialization

void Graph(){
	
	cin >> n;
	
	for(int i = 1; i <= 9; i++){
		dp[1][i] = 1;
	}
	dp[1][0] = 0;
}

void Solution(){
	for (int i = 2; i <= n; i++){
		for (int j = 0; j <= 9; j++){
			if (j==0) {
				dp[i][j] = (dp[i - 1][j + 1]) % 1000000000;
			} else if (j==9){
				dp[i][j] = (dp[i - 1][j - 1]) % 1000000000;
			} else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			}
		}
	}
	
	long long ans = 0;
	for(int k = 0; k <= 9; k++){
		ans += (dp[n][k]);
	}
	cout << ans % 1000000000;
}

int main() {
	Graph();
	Solution();
}