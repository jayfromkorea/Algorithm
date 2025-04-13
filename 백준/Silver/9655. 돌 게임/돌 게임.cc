#include <iostream>
using namespace std;

int main() {
	int n;
	bool dp[1001];
	
	cin >> n;
	dp[1] = true;
	dp[2] = false;
	dp[3] = true;
	
	for (int i = 4; i <= n; i++){
		if(dp[i-1] == true && dp[i-3] == true){
			dp[i] = false;
		} else {
			dp[i] = true;
		}
	}
	string result = (dp[n] == true) ? "SK" : "CY";
	cout << result;
}