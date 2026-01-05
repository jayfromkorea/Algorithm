using namespace std;
#include <iostream>
#include <vector>

int main(){
    
    int tc; // The number of test cases
    int n; // The num of coins
    int target; // The target to meet
    int dp[21][10001];
    int coin[21];
    
    cin >> tc;
    while(tc--){
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> coin[i];
            dp[i][0] = 1; // Only single case exists when the target is 0: picking 0 coin
        }
        cin >> target;
        for (int i = 0; i < n; i++){
            for (int j = 1; j <= target; j++){
                dp[i][j] = 0;
                if (i-1 >= 0) dp[i][j] += dp[i-1][j];
                if (j - coin[i] >= 0) dp[i][j] += dp[i][j - coin[i]];
            }
        }
        cout << dp[n-1][target] << '\n';
        
    }
}