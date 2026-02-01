#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, u, v;
    //vector<int> adj[1005];
    cin >> n;
    int southest = 1001;
    bool unique = true;
    int x;
    while (n--){
        cin >> u >> v;
        if (v < southest) {
            southest = v;
            x = u;
        }
    }
    
   cout << x << ' ' << southest << '\n';
}