#include <iostream>
#include <queue>
using namespace std;

int n, k;
int moves[3] = {-1, 1, 2};
bool vis[100001];
int sec = 0;
queue<int> q;

void seek(int n){
    vis[n] = true;
    q.push(n);
    
    while (!q.empty()) {
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            int pos = q.front();
            q.pop();
            
            for (int j = 0; j < 3; j++) {
                int next;
                if (j == 2) {
                    next = 2 * pos;
                } else {
                    next = pos + moves[j];
                }

                if (next < 0 || next > 100000 || vis[next]) continue; 
                
                if (next == k) {
                    cout << sec + 1 << '\n';  
                    return;
                }
                
                vis[next] = true;
                q.push(next);
            }
        }

        sec++;
    }
}

int main() {
    cin >> n >> k;
    if (n == k) {
        cout << 0 << '\n';
    } else {
        seek(n);
    }
    return 0;
}
