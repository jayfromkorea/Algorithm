#include <iostream>
using namespace std;



int main() {
	int n;
	cin >> n;
	int dp[n+1];
	int route[n+1] = {};
	for (int i = 1; i <= n; i++) dp[i] = n + 1;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	route[1] = 1;
	route[2] = 1;
	route[3] = 1;
	for (int i = 4; i <= n; i++){
		if(i % 3 == 0){
			if (dp[i] > dp[i/3]){
				dp[i] = dp[i/3] + 1;
				route[i] = i/3;
			}
			
		}
		if(i % 2 == 0){
			if (dp[i] > dp[i/2]){
				dp[i] = dp[i/2] + 1;
				route[i] = i/2;
			}
			
		}
		
		if (dp[i] > dp[i-1]){
			dp[i] = dp[i-1] + 1;
			route[i] = i-1;
		}
		
	}
	// print out results
		cout << dp[n] << '\n';
		cout << n << ' ';
		while (n > 1){
			cout << route[n] << ' ';
			n = route[n];
		}
}