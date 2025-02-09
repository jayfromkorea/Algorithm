#include <iostream>
using namespace std;

int main() {
	int dp[12], n, t, last = 4;
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;
	
	cin >> t;
	
	for (int i = 0; i < t; i++){
		cin >> n;
		if (last < n){
			for (int i = last + 1; i <= n; i++){
				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
			}
			last = n;
			cout << dp[n] << "\n";
		} else {
			cout << dp[n] << "\n";
		}
	}
	
}