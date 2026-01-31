#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1005];
int arr[1005];

int func(int cur){
    if (dp[cur]) return dp[cur];
    dp[cur] = 1;
    for (int i = cur; i < n; i++){
        if (arr[i] > arr[cur]) {
            dp[cur] = max(dp[cur], func(i) + 1);
        }
    }
    return dp[cur];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, func(i));
    cout << ans << '\n';
}
