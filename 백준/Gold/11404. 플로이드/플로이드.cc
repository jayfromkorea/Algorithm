#include <algorithm>
#include <iostream>
using namespace std;
// Floyd
// 2026.04.27

int min_dis[105][105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int u, v, c;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j) {
                min_dis[i][j] = 0;
                continue;
            }
            min_dis[i][j] = 1e9;
        }
    }
    
    while (m--){
        cin >> u >> v >> c;
        min_dis[u][v] = min(min_dis[u][v], c);
    }
    
    for (int det = 1; det <= n; det++){ // det: detour
        for (int i = 1; i <= n; i++){
            for (int j =1; j <= n; j++){ 
                //if (min_dis[i][det] == 1e9 || min_dis[det][j] == 1e9) continue; // if there is no edge connecting two nodes
                min_dis[i][j] = min(min_dis[i][j], min_dis[i][det] + min_dis[det][j]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (min_dis[i][j] == 1e9) cout << 0 << ' ';
            else cout << min_dis[i][j] << ' ';
        }
        cout << '\n';
    }
}