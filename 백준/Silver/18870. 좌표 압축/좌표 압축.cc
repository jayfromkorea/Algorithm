#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int binary(int k, int n){
	int lo = 0;
	int hi = n-1;
	
	int mid = (lo + hi) / 2;
	
	while (lo <= hi){
		if (k == v[mid]) return mid;
		if (k < v[mid]) hi = mid-1;
		else lo = mid + 1;
		mid = (lo + hi) / 2;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, p;
	
	cin >> n;
	int cor[n];
	int dup[n];
	
	
	for (int i = 0; i < n; i++){
		cin >> p;
		cor[i] = p;
		dup[i] = p;
	}
	
	sort(dup, dup + n);
	int pre = dup[0];
	v.push_back(dup[0]);
	for (int i = 1; i < n; i++){
		if (pre != dup[i]) v.push_back(dup[i]);
		pre = dup[i];
	}
	
	for (int e : cor){
		cout << binary(e, v.size()) << ' ';
	}
}