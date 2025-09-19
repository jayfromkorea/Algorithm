#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, target;
	
	cin >> n;
	
	int arr[n+1];
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	
	cin >> m;
	
	while (m--) {
		cin >> target;
		
		if (binary_search(arr, arr+n, target)) {
        	cout << "1" << '\n';
    	} else {
        	cout << "0" << '\n';
    	}
	}
}