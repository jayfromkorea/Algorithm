// Union-find review
// 09/Nov/2025

#include <iostream>
using namespace std;

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
	// your code goes here
	return 0;
}
