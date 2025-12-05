#include <iostream>
#include <utility>
#include <queue>
#define W first
#define V second
using namespace std;

int v, e, n;
vector<pair<int, int>> adj[20001]; // {weight, v}
const int INF = 1e9 + 10;

void Djikstra(int str){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {weight, v}
	int dis[20001]; // The array to store minimal distances
	for (int i = 1; i <= v; ++i) dis[i] = INF;
	dis[str] = 0;
	
	
	pq.push({0, str}); // Pushing the start
	while (!pq.empty()){
		auto nxt = pq.top();
		pq.pop();
		if (dis[nxt.V] == nxt.W) {
			for (pair<int, int> e : adj[nxt.V]) {
				if (dis[e.V] > dis[nxt.V] + e.W){
					dis[e.V] = dis[nxt.V] + e.W;
					pq.push({dis[e.V], e.V});
				}
			}
		}
	}
	
	//Output
	for (int i = 1; i <= v; i++){
		if (dis[i] == INF) cout << "INF\n";
		else cout << dis[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// Input
	cin >> v >> e >> n;
	
	int a, b, c; // v, u, w
	while(e--) {
		cin >> a >> b >> c;
		adj[a].push_back({c, b}); // {weight, v}
	}
	
	Djikstra(n);
}