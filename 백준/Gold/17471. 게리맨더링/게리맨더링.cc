#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

int pop[12]; // An array store numbers of populations
 vector<int> adj[12];

int connected(int mask){ // Checks if cities are connected employing DFS, return the sum of population
    stack<int> s;
    int sum = 0;
    int i = 0;
    while (!(mask & (1 << i))) i++;
    //DFS
    s.push(i + 1);
    while (!s.empty()){
        int cur = s.top();
        s.pop();
        if (!(mask & (1 << cur-1))) continue;
        mask &= ~(1 << (cur-1)); // Mark the visited bit false --> at the end, if mask equals 0, evert city connected
        sum += pop[cur];
        for (int v : adj[cur]){
            if (!(mask & (1 << v-1))) continue;
            s.push(v);
        }
    }
    if (mask) return -1;
    else return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; // The num of cities
    int cn; // The num of connections of each constituency
    int to;
    
   
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) cin >> pop[i];
    for (int i = 1; i <= n; i++) {
        cin >> cn;
        for (int j = 0; j < cn; j++){
            cin >> to;
            adj[i].push_back(to);
            adj[to].push_back(i);
        }
    }
    
    int ans = 1e9;
    for (int mask = 1; mask < (1 << (n-1)); mask++){ // ***IMPORTATN*** 0-based mask
        int const_A = connected(mask);
        if (const_A == -1) continue;
        int const_B = connected(~mask & ((1 << n) - 1));
        if (const_B == -1) continue;
        int diff = const_A - const_B;
        if (ans > abs(diff)) ans = abs(diff);
    }
    if (ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}