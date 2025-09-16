#include <iostream>
#include <queue>
using namespace std;

struct tomato {
	int x, y, z;
};

int n, m, h; // n for rows, m for columns, h for heights
int yard[101][101][101];
bool vis[101][101][101];
queue<tomato> q;

int BFS(){
	int count = 0; // to track each layer (the number of days)
	int interval = q.size(); // the size of each chunck of layers (the number of subsequent ripe tomatos)
	int dx[6] = {1, -1, 0, 0, 0, 0};
	int dy[6] = {0, 0, 1, -1, 0, 0};
	int dz[6] = {0, 0, 0, 0, 1, -1};
	
	while (!q.empty()){
		tomato cur = q.front();
		q.pop();
		interval--; // decrement whenever a ripe tomato gets calculated
		
		for (int i = 0; i < 6; i++){
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nz = cur.z + dz[i];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue; // outOfBounds
			if (vis[nx][ny][nz]) continue; // if visited skip
			vis[nx][ny][nz] = 1;
			q.push({nx, ny, nz});
		}
		
		if (interval == 0) { // if all of the ripe ones at the day are taken care of
			count++; // increment the number of days;
			interval = q.size(); // update the size of the interval
		}
	}
	
	for (int i = 0; i < h; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < m; k++){
				if (!vis[j][k][i]) {
					return 0;
				}
			}
		}
	}
	
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> m >> n >> h;
	
	for (int i = 0; i < h; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < m; k++){
				cin >> yard[j][k][i];
				if (yard[j][k][i] == 1) { 
					vis[j][k][i] = 1;
					q.push({j, k, i});
				} else if (yard[j][k][i] == -1) { 
					vis[j][k][i] = 1;
				}
			}
		}
	}
	
	
	
	cout << BFS() - 1 << '\n';
}