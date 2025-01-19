#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n, m, num;
	set<int> set;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		set.insert(num);
	}
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> num;
		if (set.find(num) != set.end()) {
			cout << 1 << "\n";
		} else {
			cout << 0 << "\n";
		}
	}
}