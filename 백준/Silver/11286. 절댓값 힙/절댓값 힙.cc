#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Compare {
public:
	bool operator()(int a, int b) {
		int p = a;
		int q = b;
		if (a < 0) a *= -1;
		if (b < 0) b *= -1;
		
		if (a == b) {
			if (q < p) return true;
		} else if (b < a) return true;
		return false;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int, vector<int>, Compare> pq;
	int n, k;
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> k;
		if (k == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		} else {
			pq.push(k);
		}
	}
	
}