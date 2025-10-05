#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, s;
	cin >> n >> s;
	int arr[n + 1];
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	int mini = n + 1;
	int st = 0;
	int en = 0;
	int sum = arr[0];
	while (en < n){
		if (sum < s) {
			en++;
			sum += arr[en];
		}
		else {
			mini = min(mini, en - st + 1);
			//cout << sum << ' ' << st << ' ' << en << ' ' << mini << '\n';
			sum -= arr[st];
			st++;
		}
	}
	if (mini == n + 1) mini = 0;
	cout << mini << '\n';
}