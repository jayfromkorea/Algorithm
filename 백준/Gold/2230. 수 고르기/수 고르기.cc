#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	int arr[n + 1];
	
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int st = 0;
	int en = 0;
	int ans = 0x7fffffff;
	int diff = ans;
	while (en < n){
		diff = arr[en] - arr[st];
		if (diff < m) en++;
		else {
			ans = min(ans, diff);
			st++;
		}
	}
	cout << ans << '\n';
}