#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool vis[1001];

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v + 1); // allocate adjacency list
    queue<int> q;
    int str, end;

    // input edges
    for (int i = 0; i < e; i++) {
        cin >> str >> end;
        adj[str].push_back(end);
        adj[end].push_back(str);
    }

    // BFS
    int count = 0;
    for (int i = 1; i <= v; i++) {
        if (vis[i]) continue;
        count++;
        q.push(i);
        vis[i] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nxt : adj[cur]) {
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }

    cout << count << '\n';
    return 0;
}

