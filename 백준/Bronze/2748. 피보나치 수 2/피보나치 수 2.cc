#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	
	vector<long> dp;
	dp.push_back(0);
	dp.push_back(1);
	
	cin >> n;
	
	for (int i = 2; i <= n; i++){
		dp.push_back(dp[i-2] + dp[i-1]);
	}
	cout << dp[n];
}