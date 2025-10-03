#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[500001]; // an array to store nums
int b[500001]; // an array to store targets

int lower_bound(int k){
	int lo = 0;
	int hi = n;
	
	int mid = (lo + hi) / 2;
	
	while (lo <= hi){
		if (lo == hi) return mid; // doesn't matter whether to reutrn hi or lo or mid
		if (k <= a[mid]) hi = mid;
		else lo = mid + 1; // if (k > a[mid])
		mid = (lo + hi) / 2;
	}
	return 0;
}

int upper_bound(int k){
	int lo = 0;
	int hi = n;
	
	int mid = (lo + hi) / 2;
	
	while (lo <= hi){
		if (lo == hi) return mid; // doesn't matter whether to reutrn hi or lo or mid
		if (k < a[mid]) hi = mid;
		else lo = mid + 1; // if (k >=` a[mid])
		mid = (lo + hi) / 2;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	
	for (int i = 0; i < m; i++){
		cout << upper_bound(b[i]) - lower_bound(b[i]) << ' ';
	}
}
