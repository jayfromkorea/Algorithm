#include <iostream>
#include <utility>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[502][502], num, length, max_length = 0;
bool vis[502][502];

void BFS(int p, int k, int cx, int cy);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int p, q;
	num = 0;
	cin >> p >> q;
	for (int i = 0; i < p; i++){
		for (int j = 0; j < q; j++){
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < p; i++){
		for (int j = 0; j < q; j++){
			if (board[i][j] == 1 && vis[i][j] != 1) {
				//cout << num << '\n';
				BFS(p, q, i, j);
			}
		}
	}
	
	cout << num << '\n' << max_length << '\n';
}

void BFS(int p, int k, int cx, int cy) {
	num++;
	length = 0;
	int nx = cx, ny = cy;
	queue<pair<int, int>> q;
	
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, -1, 0, 1};
	
	vis[nx][ny] = 1;
	q.push({nx, ny});
	
	while(!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		length++;
		//cout << '(' << cur.X << ", " << cur.Y << ") -> ";
		for (int i = 0; i < 4; i++){
			nx = cur.X + dx[i];
			ny = cur.Y + dy[i];
			if (nx >= p || nx < 0 || ny >= k || ny < 0) continue;
			if (board[nx][ny] != 1 || vis[nx][ny]) continue;
			vis[nx][ny] = 1;
			q.push({nx, ny});
		}
		if (length > max_length) max_length = length;
		//cout << num << '\n' << max_length << '\n';
	}
}