#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int n, m; // n for rows, m for columns
int yard[1001][1001];
bool vis[1001][1001];
queue<pair<int, int>> q;

int BFS(){
	int count = 0; // to track each layer (the number of days)
	int interval = q.size(); // the size of each chunck of layers (the number of subsequent ripe tomatos)
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	
	while (!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		interval--; // decrement whenever a ripe tomato gets calculated
		
		for (int i = 0; i < 4; i++){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // outOfBounds
			if (vis[nx][ny]) continue; // if visited skip
			vis[nx][ny] = 1;
			q.push({nx, ny});
		}
		
		if (interval == 0) { // if all of the ripe ones at the day are taken care of
			count++; // increment the number of days;
			interval = q.size(); // update the size of the interval
		}
	}
	
	for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (!vis[i][j]) {
					//cout << "-1" << '\n';
					return 0;
				}
			}
		}
	
	
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> m >> n;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> yard[i][j];
			if (yard[i][j] == 1) {
				vis[i][j] = 1;
				q.push({i, j});
			} else if (yard[i][j] == -1) {
				vis[i][j] = 1;
			}
		}
	}
	
	
	
	cout << BFS() - 1 << '\n';
}