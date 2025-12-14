#include <iostream>
#include <queue>
#define P first // Position
#define T second // Cost
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_POS = 100001;
int t[MAX_POS]; // The minimal time found, to reach each point

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k; // The position of the brother and sister repectively
	cin >> n >> k;
	
	for (int i = 0; i < MAX_POS; i++) t[i] = INF;
	t[n] = 0;
	
	//BFS
	queue<pair<int, int>> q; // {position, cost}
	int nxt[3] = {-1, 1, 2}; // The choices of the next move
	q.push({n, 0});
	
	while (!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		
		for (int i = 0; i < 3; i++){
			int np;
			if (i != 2) {
				np = cur.P + nxt[i]; // The next position
			} else {
				np = cur.P * nxt[i]; // The next position
			}
			
			if (np < 0 || np >= MAX_POS) continue; // when out of bounds, skip
			
			if (i != 2) {
				if (cur.T + 1 < t[np]) {
					q.push({np, cur.T + 1}); // Increment time when it's not *2
					t[np] = cur.T + 1; // Update the minimal time
				}
			} else {
				if (cur.T < t[np]) {
					q.push({np, cur.T}); // Don't increment if it's *2
					t[np] = cur.T; // Update the minimal time
				}
			}
			//The first i == 0,  which means nxt[0] is -1, which gets factored in no matter the next line
			if (cur.P > k) break; // If the current position is beyond "k", skip advancements
		}
	}
	cout << t[k] << '\n';
}