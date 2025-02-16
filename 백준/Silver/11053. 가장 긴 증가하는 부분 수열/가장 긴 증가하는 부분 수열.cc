#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, el, ans = 0;
	
	vector<int> dp, array;
	
	cin >> n;
	
	dp.assign(n, 1);
	
	for(int i = 0; i < n; i++){
		cin >> el;
		array.push_back(el);
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++){
			if (array[i] > array[j]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		ans = max(dp[i], ans);
	}
	cout << ans;
}