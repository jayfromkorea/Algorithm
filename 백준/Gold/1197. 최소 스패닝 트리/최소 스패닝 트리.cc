#include <bits/stdc++.h>
using namespace std;

int p[100001];

int find(int a) {
    if (p[a] < 0) return a;
    return p[a] = find(p[a]);
}

bool uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (p[a] > p[b]) swap(a, b);
    p[a] += p[b];
    p[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, e;
    cin >> v >> e;

    vector<tuple<int,int,int>> edges;

    for (int i = 0; i < v; i++)
        p[i] = -1;

    for (int i = 0; i < e; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back(make_tuple(weight, from, to));
    }

    sort(edges.begin(), edges.end());

    int count = 0;
    int sum = 0;

    for (auto &t : edges) {
        int w = get<0>(t);
        int u = get<1>(t);
        int v1 = get<2>(t);
        if (uni(u, v1)) {
            sum += w;
            count++;
            if (count == v - 1) break;
        }
    }

    cout << sum << "\n";
}