#include <iostream>
#include <algorithm>
using namespace std;

int spe[100001]; // specimen
int n, m;

bool binary(int k){
	int lo = 0;
	int hi = n-1;
	
	int mid = (lo + hi) / 2;
	
	while (lo <= hi){
		//cout << "k: " << k << ' ' << "spe[mid]: " << spe[mid] << '\n';
		if (k == spe[mid]) return true;
		if (k < spe[mid]) hi = mid - 1;
		else lo = mid + 1;
		mid = (lo + hi) / 2;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int p;
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> spe[i];
	}
	sort(spe, spe + n); // imperative for binary search
	
	cin >> m;
	
	for (int i = 0; i < m; i++){
		cin >> p;
		cout << binary(p) << '\n';
	}
	
	
}
