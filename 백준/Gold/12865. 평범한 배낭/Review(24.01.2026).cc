#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int dp[105][100005];
int W[105];
int V[105];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	
	//INPUT
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> W[i] >> V[i];
	//DP
	for (int i = 0; i < n; i++) {
	    for (int j = 1; j <= k; j++){
	        if (i-1 >= 0) {
	            dp[i][j] = dp[i-1][j];
	            if (j >= W[i]) dp[i][j] = max(dp[i][j], dp[i-1][j - W[i]] + V[i]);
	        }
	        else if (W[i] <= j) dp[i][j] = V[i];
	    }
	    
	}
	
	cout << dp[n-1][k] << '\n';
	
    return 0;
}
