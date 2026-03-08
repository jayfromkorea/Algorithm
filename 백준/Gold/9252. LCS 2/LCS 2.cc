#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005]; // The max length of subsequence with the limit of indices of i and j respectively

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a;
	string b;
	cin >> a >> b;
	int p = a.size();
	int q = b.size();

    int i = 0;
    int j = 0;
    
    for (int i = 1; i <= p; i++){
        for (int j = 1; j <= q; j++){
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
        }
    }
    
    string ans = "";
    int f = p;
    int s = q;
    while (f > 0 && s > 0){
        if (a[f-1] == b[s-1]){
            ans += a[f-1];
            f--;
            s--;
        } else if (dp[f-1][s] > dp[f][s-1]) {
            f--;
        } else {
            s--;
        }
    }
    reverse(ans.begin(), ans.end());
    
    cout << dp[p][q] << '\n' << ans;
    
}