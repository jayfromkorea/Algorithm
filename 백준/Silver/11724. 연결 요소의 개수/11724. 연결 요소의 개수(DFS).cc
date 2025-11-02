#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool vis[1001];

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v + 1); // allocate adjacency list
    stack<int> st;
    int str, end;

    // input edges
    for (int i = 0; i < e; i++) {
        cin >> str >> end;
        adj[str].push_back(end);
        adj[end].push_back(str);
    }

    // DFS
    int count = 0;
    for (int i = 1; i <= v; i++) {
        if (vis[i]) continue;
        count++;
        st.push(i);
        vis[i] = true;
        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            for (int nxt : adj[cur]) {
                if (vis[nxt]) continue;
                st.push(nxt);
                vis[nxt] = true;
            }
        }
    }

    cout << count << '\n';
    return 0;
}
