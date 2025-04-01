#include <iostream>
using namespace std;

int arr[2][100001];
int dp[2][100001];

int n;

void Input(){
	cin >> n;
	for(int i = 0; i <= 1; i++){
		for (int j = 1; j <= n; j++){
			cin >> arr[i][j];
		}
	}
}

void Solution(){
	dp[0][1]=arr[0][1];
	dp[1][1]=arr[1][1];
	for (int i = 2; i <= n; i++){
		dp[0][i] = max(dp[1][i-2], dp[1][i-1]) + arr[0][i];
		dp[1][i] = max(dp[0][i-2], dp[0][i-1]) + arr[1][i];
	}
	cout << max(dp[0][n], dp[1][n]) << "\n";
}

int main() {
	int t;
	cin >> t;
	while(t--){
		Input();
		Solution();
	}
}