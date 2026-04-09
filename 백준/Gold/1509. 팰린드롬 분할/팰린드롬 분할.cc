#include <bits/stdc++.h>
using namespace std;

int dp[2505]; // dp[i]: The mnimum num of partions in s[0...i]
bool isPal[2501][2501];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();
    
    
    for (int i = 0; i < n; i++) isPal[i][i] = true; // (length: 1) Every character itslef is a palindrome
    for(int i = 0; i < n - 1; i++){
        if (s[i] == s[i + 1]) isPal[i][i+1] = 1; // (length: 2) Check equality
    }
    for (int len = 3; len <= n; len++){ // (length: 3) 
        for (int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            if (s[i] == s[j] && isPal[i+1][j-1]) isPal[i][j] = 1;
        }
    }
    
    for (int i = 0; i < n; i++){
        if (isPal[0][i]) {
            dp[i] = 1;
        } else {
            dp[i] = 1e9;
            for (int j = 0; j < i; j++){
                if (isPal[j + 1][i]) dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    
    cout << dp[n - 1] << '\n';
}