#include <iostream>
#include <queue>
using namespace std;

int array[1000001];
//int visited[1000001];

void BFS(){
	int n;
	cin >> n;
	queue<int> q;
	array[1] = 0;
	//visited[1] = 0;
	q.push(1);
	while (!q.empty()){
		int adj;
		int cur = q.front();
		if(cur == n) {
            cout << array[cur];
            return;
        }
		q.pop();
		for (int i = 1; i < 4; i++){
			if (i == 1) adj = cur + i;
			else adj = cur * i;
			if (adj > n) continue;
			if (array[adj] != 0) continue;
			array[adj] = array[cur] + 1;
			//visited[adj] = 1;
			q.push(adj);
		}
	}
	//cout << array[n] << '\n';
}

int main() {
	BFS();
}
