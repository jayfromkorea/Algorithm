#include <iostream>
#include <vector>
using namespace std;

vector<int> p(1000005, -1);

int find(int a){
	if (p[a] < 0){
		return a;
	}
	return p[a] = find(p[a]); // Path Compression
}

bool uni(int a, int b){
	int u = find(a);
	int v = find(b);
	if (u == v) return false; // already in the same union
	if (p[v] < p[u]) swap(u, v); // rank of u <= rank of v
	if (p[v] == p[u]) p[u]--; // edge case: the same rank
	p[v] = u;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc, n, k, m; // test cases, users, connections, pairs
	
	cin >> tc; // the number of test cases
	int a, b; // variables for connections (A to B)
	for (int i = 1; i <= tc; i++){
		cout << "Scenario " << i << ":\n";
		fill(p.begin() + 1, p.begin() + n + 1, -1);
		cin >> n >> k;
		while(k--){
			cin >> a >> b;
			uni(a, b);
		}
		cin >> m; // pairs to verify
		while (m--){
			int p1, p2;
			cin >> p1 >> p2;
			if (find(p1) == find(p2)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		cout << '\n';
	}
}