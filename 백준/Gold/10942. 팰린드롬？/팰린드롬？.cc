// 26 Feb 2026
// BOJ 10942: 펠린드롬?
// DP

#include <iostream>
using namespace std;

bool dp[2005][2005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    int nums[2005];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    cin >> m;
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    for (int i = 1; i < n; i++) dp[i][i+1] = (nums[i] == nums[i+1]) ? 1 : 0;
    for (int len = 3; len <= n; len++){
        for (int i = 1; i <= n - len + 1; i++){
            int j = i + len - 1;
            dp[i][j] = (nums[i] == nums[j] && dp[i+1][j-1]);
        }
    }
    
    int s, e;
    while (m--){
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
    
}