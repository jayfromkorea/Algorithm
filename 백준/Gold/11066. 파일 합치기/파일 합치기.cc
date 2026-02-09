#include <iostream>
#include <algorithm>
using namespace std;

int dp[505][505];
int file[505];
int prefix[505];

int sum(int a, int b){
    if (a == 0) return prefix[b];
    return prefix[b] - prefix[a - 1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; // Test cases
    cin >> t;
    
    
    while (t--){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> file[i];
            prefix[i] = file[i] + (i ? prefix[i-1] : 0);
            dp[i][i] = 0;
        }
        for (int len = 1; len < n; len++){
            for (int dx = 0; dx + len < n; dx++){
                int dy = dx + len;
                dp[dx][dy] = 1e9;
                for (int mid = dx; mid < dy; mid++){
                    dp[dx][dy] = min(dp[dx][dy], dp[dx][mid] + dp[mid + 1][dy] + sum(dx, dy));
                    //cout << dx << ' ' << mid << ' ' << dy << ' ' << dp[dx][dy] << '\n';
                }
            }
        }
        cout << dp[0][n-1] << '\n';
    }
    
    
    
}