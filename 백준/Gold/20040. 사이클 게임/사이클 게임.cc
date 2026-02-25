// 25 Feb 2026
// BOJ 20040: Cycle Check
// Graph
// Union-Find


#include <iostream>
#include <vector>
using namespace std;

int p[500005]; // parents
int r[500005]; // ranks
int find(int a){
    if (p[a] == a) return a;
    return p[a] = find(p[a]);
}

bool unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (r[a] < r[b]) swap(a, b);
    if (r[a] == r[b]) r[a]++;
    p[b] = a;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) p[i] = i;
    
    // Input
    int u, v;
    for (int i = 0; i < m; i++){
        cin >> u >> v;
        if (find(u) == find(v)) {
            cout << i + 1;
            return 0;
        }
        unite(u, v);
    }
    cout << 0 << '\n';
}