#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	priority_queue<int, vector<int>, greater<int>> pq;
	int n, a;
	int sum = 0;
	cin >> n;
	while (n--){
		cin >> a;
		pq.push(a);
	}
	long long ans = 0;
	while (pq.size() > 1){
		int ls = 0; // the last sum
		for (int i = 0; i < 2; i++) {
			ls += pq.top();
			pq.pop();
		}
		ans += ls;
		pq.push(ls);
	}
	cout << ans << '\n';
}