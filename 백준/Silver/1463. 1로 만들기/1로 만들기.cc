#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int p, dp[1000001];
	
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	
	cin >> p;
	
	for (int i = 4; i <= p; i++){
		dp[i] = dp[i - 1] + 1;
		
		if (i % 3 == 0){
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		
		if (i % 2 == 0){
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}
	
	cout << dp[p];
	return 0;
}