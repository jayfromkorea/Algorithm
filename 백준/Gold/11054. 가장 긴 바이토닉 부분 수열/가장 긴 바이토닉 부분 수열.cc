#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a, ans = 0, arr[1001], in[1001], de[1001], dp[1001];
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		in[i] = 1;
		de[i] = 1;
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j < i; j++){
			if (arr[i] > arr[j]){
				in[i] = max(in[i], in[j] + 1);
			} 
		}
	}
	for (int i = n; i >= 1; i--){
		for (int k = n; k > i; k--){
			if (arr[i] > arr[k]){
				de[i] = max(de[i], de[k] + 1);
			}
		}
	}
	 for (int i = 1; i <= n; i++) {
        dp[i] = in[i] + de[i] - 1;  
        ans = max(ans, dp[i]);
    }
	cout << ans << "\n";
}