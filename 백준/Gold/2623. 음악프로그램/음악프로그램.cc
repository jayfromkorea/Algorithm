#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, m; // n: The number of performers, m: the number of PDs
    cin >> n >> m;
    vector<int> adj[n+5]; // Adjacency list
    int indegree[n+5];
    priority_queue<pair<int, int>> pq; // <indegree, node>
    
    for (int i = 1; i <= n; i++) indegree[i] = 0; // Initialization
    
    // Input
    int a;
    int num; // The number of performers a PD gets allocated
    for (int i = 0; i < m; i ++) {
        cin >> num;
        int prev, cur;
        cin >> prev;
        for (int j = 1; j < num; j++) {
            cin >> cur;
            adj[prev].push_back(cur);
            indegree[cur]++;
            prev = cur;
        }
    }
    
    // Topological sort
    vector<int> ans; // Answer array
    for (int i = 1; i <= n; i++) if (indegree[i] == 0) pq.push({indegree[i], i});
    while (!pq.empty()){
        pair<int, int> cur = pq.top();
        pq.pop();
        ans.push_back(cur.second);
        for (int nxt : adj[cur.second]){
            indegree[nxt]--;
            if (indegree[nxt] == 0) pq.push({indegree[nxt], nxt});
        }
    }
    
    // Output
    if ((int)ans.size() == n) for (int answer : ans) cout << answer << '\n';
    else cout << 0 << '\n';
}
