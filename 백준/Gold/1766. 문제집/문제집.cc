#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int in[32005]; // All set to 0

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, con; // con: conditions
    cin >> n >> con;
    vector<int> out[32001]; // Stores out degrees (nodes it points to)
    
    int u, v;
    while (con--){
        cin >> u >> v;
        in[v]++; // Keep track of the number of indegrees
        out[u].push_back(v); // Keep track of the node it points to
    }
    
    // Topological sort
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // First, add all the nodes with 0 indegree
    for (int i = 1; i <= n; i++){
        if (in[i] == 0) pq.push(i);
    }
    
    // Next, execute the general Topological Sort
    while (!pq.empty()){
        int cur = pq.top();
        pq.pop();
        cout << cur << ' ';
        for (int to : out[cur]) {
           in[to]--;
           if (in[to] == 0) pq.push(to);
        }
    }
    
    
}