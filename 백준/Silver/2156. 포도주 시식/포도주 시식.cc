#include <iostream>
using namespace std;

int n;
int dp[10001];
int arr[10001];

void Input(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> arr[i+1];
	}
}

void Solution(){
	dp[1] = arr[1];
	dp[2] = dp[1]+arr[2];
	
	for (int i = 3; i <= n; i++){
		dp[i] = max(arr[i] + dp[i-2], arr[i] + arr[i-1] + dp[i-3]);
		dp[i] = max(dp[i], dp[i-1]);
	}
	cout << dp[n] << "\n";
}

int main() {
	Input();
	Solution();
	return 0;
}