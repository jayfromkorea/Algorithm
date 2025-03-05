#include <iostream>
using namespace std;

int main() {
	int n;
	
	cin >> n;
	long dp[n + 1];
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 3; i < n + 1; i++){
		dp[i] = dp[i-2] + dp[i-1];
	}
	
	cout << dp[n];
}