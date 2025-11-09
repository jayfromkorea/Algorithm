#include <iostream>
#include <vector>
using namespace std;

vector<int> p(1000001, -1); // parents

int find(int a){ // implementing "Path Compression"
	if (p[a] < 0){
		return a;
	}
	return p[a] = find(p[a]); // every node on the path points to its root
}

bool uni(int a, int b){ // implementing "Kruskal's Algorithm"
	int u = find(a);
	int v = find(b);
	if (u == v) return false; // in the same union
	if (p[u] > p[v]) swap(u, v); // rank of u <= rank of v
	if (p[u] == p[v]) p[u]--; // exception: rank of u == rank of v
	p[v] = u;
	
	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m; // num of nodes, num of operation
	cin >> n >> m;
	
	int a, b, c;
	
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		if (a == 0) uni(b, c);
		else if (a == 1) {
			if (find(b) == find(c)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
}