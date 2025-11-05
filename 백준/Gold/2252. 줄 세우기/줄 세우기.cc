#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> adj[32001]; // adjacency list
	vector<int> ans;
	int indegree[32001] = {0};
	queue<int> q;
	int n, m; // num of students, num of height comparisons
	
	cin >> n >> m;
	
	// input
	int a, b;
	while(m--) {
		cin >> a >> b;
		adj[a].push_back(b);
		indegree[b]++;
	}
	
	//queue initialization
	for (int i = 1; i <= n; i++){
		if (indegree[i] == 0) q.push(i);
	}
	// topological sort
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		ans.push_back(cur);
		for (int next : adj[cur]){
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << ' ';
	}
}