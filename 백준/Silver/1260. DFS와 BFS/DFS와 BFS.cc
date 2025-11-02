#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> adj[1005];
bool vis1[1005];
stack<int> st;
bool vis2[1005];
queue<int> q;

void dfs(int a){
	if (vis1[a]) return;
	st.push(a);
	vis1[a] = true;
	cout << a << ' ';
	for (int el : adj[a]){
		dfs(el);
	}
}

void bfs(int a){
	q.push(a);
	vis2[a] = true;
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int el : adj[cur]){
			if (vis2[el]) continue;
			q.push(el);
			vis2[el] = true;
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int v, e, str; // vertex, edge, start
	cin >> v >> e >> str;
	//input edges
	int from, to;
	for (int i = 0; i < e; i++){
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	
	for (int i = 1; i <= v; i++){
		sort(adj[i].begin(), adj[i].end());
	}
	
	dfs(str);
	cout << '\n';
	bfs(str);
}
