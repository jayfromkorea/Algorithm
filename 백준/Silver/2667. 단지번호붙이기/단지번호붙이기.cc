#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int n;
int cnt = 0; 
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[26][26];
bool visited[26][26];
queue<pair<int, int>> q;
vector<int> v;

void bfs(pair<int, int> start) {
    cnt++;
    int units = 1;
    visited[start.X][start.Y] = 1;
    q.push({start.X, start.Y});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] != '1' || visited[nx][ny]) continue;
            
            visited[nx][ny] = 1;
            q.push({nx, ny});
            //cout << "units incremented! --> " << units << '\n';
            units++;
        }
    }
    //cout << "units: " << units << '\n';
    v.push_back(units);
}

int main() {
	string line;
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> line;
        for (int j = 0; j < n; j++) {
            board[i][j] = line[j];
        }
    }
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < n; j++){
    		if (board[i][j] != '1' || visited[i][j]) continue;
    		bfs({i, j});
    	}
    }
    cout << cnt << '\n';
    sort(v.begin(), v.end());
    for (int e : v) {
        cout << e << '\n';
    }
}
