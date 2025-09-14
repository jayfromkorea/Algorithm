#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int a[51];
	int b[51];
	
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	sort(a, a + n);
	sort(b, b + n, greater<int>());
	
	int ans = 0;
	for (int i = 0; i < n; i++) ans += (a[i] * b[i]);
	
	cout << ans << '\n';
}