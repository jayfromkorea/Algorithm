// Baekjoon 12865

#include <iostream>
#include <algorithm>
using namespace std;

int dp[105][100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, limit; // The num of items given, and weight limit respectively
	cin >> n >> limit; // Input
	int V[105]; // The array for "values" of each item
	int W[105]; // The array for "weights" of each item

	for (int i = 0; i < n; i++) cin >> W[i] >> V[i]; // Values and weights of each item

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= limit; j++) {
			// The case where the i-th item not taken, and where taken at least once respectively
			if (i-1 >= 0) dp[i][j] = dp[i-1][j];
			if (j - W[i] >= 0) {
			    if (i-1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-W[i]] + V[i]);
			    else dp[i][j] = V[i];
			}
		}
	}
	
	cout << dp[n-1][limit] << '\n';
	
	return 0;
}
