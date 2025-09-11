#include <iostream>
#include <algorithm> // for "sort()"
#include <utility> // for "min()"
using namespace std;

int main() {
	int n;
	int rope[100001];
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> rope[i];
	}
	sort(rope, rope + n);
	
	int num = 1;
	int ans = 0;
	for (int i = n-1; i >= 0; i--){
		ans = max(ans, (n-i)*rope[i]);
	}
	
	cout << ans << '\n';
}