#include <iostream>
#include <vector>
using namespace std;

bool vis[1001];
vector<vector<int>> adj;
int v, e;
int count = 0;

void dfs(int a) {
    vis[a] = true;
    for (int nxt : adj[a]) {
        if (!vis[nxt])
            dfs(nxt);
    }
}

int main() {
    cin >> v >> e;
    adj.resize(v + 1);

    int str, end;
    for (int i = 0; i < e; i++) {
        cin >> str >> end;
        adj[str].push_back(end);
        adj[end].push_back(str);
    }

    for (int i = 1; i <= v; i++) {
        if (!vis[i]) {
            dfs(i);
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}
