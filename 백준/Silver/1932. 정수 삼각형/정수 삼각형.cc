#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	vector<vector<int>> tree(n, vector<int>(n, 0));
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			cin >> tree[i][j];
		}
	}
	
	vector<vector<int>> dp(n, vector<int>(n, 0));
	
	for (int i = 0; i < n; i++) {
        dp[n - 1][i] = tree[n - 1][i];
    }
	
	for (int i = n-2; i >= 0; i--){
		for (int j = 0; j <= i; j++){
			dp[i][j] = max(tree[i][j] + dp[i+1][j], tree[i][j] + dp[i+1][j+1]);
		}
	}
	cout << dp[0][0] << "\n";
}