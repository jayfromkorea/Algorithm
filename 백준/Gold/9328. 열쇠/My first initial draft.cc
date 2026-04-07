#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <deque>
#include <queue>
#include <cctype>
using namespace std;
#define hight first
#define width second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; // Test cases
	cin >> t;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	while (t--) {
	    int ans = 0; // The max num of docs we can take
		int h, w; // Hight & Width
		bool vis[105][105] = {false};
		bool k[30] = {false}; // True if it has the key, False otherwise
		queue<pair<int, int>> q; // A queue for BFS
		deque<string> building; // each index: hight, each string: width
		cin >> h >> w;
		// Input
		string row;
		for (int i = 0; i < h; i++) {
			cin >> row;
			building.push_front(row);
		}
		
		string keys;
		cin >> keys;
		if (keys != "0") { // Mark the keys we have
		    for (int j = 0; j < keys.length(); j++){
		        k[keys[j] - 'a'] = 1;
		    }
		}
		
		// Starting points the search could begin from
		for (int p = 0; p < w; p++){ // Check the top and bottom
		    // The bottom row
		    vis[0][p] = 1; // Mark it visited
		    if (building[0][p] == '*') continue; // A wall, can't be accessed
		    if (building[0][p] == '.') { // A free path
		        q.push({0, p});
		    } else if (building[0][p] == '$') { // A document to collect
		        ans++;
		    } else if (isupper(building[0][p])) { // If it's a door
		        if (k[tolower(building[0][p]) - 'a']) q.push({0, p}); // If the key exists, move to that point
		    } else if (islower(building[0][p])) { // it's a key
		        q.push({0, p});
		        k[building[0][p] - 'a'] = 1; // Found a key --> mark it true
		    }
		    
		    
		    // The top row
		    vis[h - 1][p] = 1; // Mark it visited
		    if (building[h - 1][p] == '*') continue;
		    if (building[h - 1][p] == '.') {
		        q.push({h - 1, p});
		    } else if (building[h - 1][p] == '$') {
		        ans++;
		    } else if (isupper(building[h - 1][p])) {
		        if (k[tolower(building[h - 1][p])] - 'a') q.push({h - 1, p});
		    } else if (islower(building[h - 1][p])) {
		        q.push({h - 1, p});
		        k[building[h - 1][p] - 'a'] = 1; // Found a key --> mark it true
		    }
		    
		    
		}
		for (int lvl = 1; lvl < h - 1; lvl ++){ // Check the both sides of the building
		
		    // The left colunm
		    vis[lvl][0] = 1; // Mark it visited
		    if (building[lvl][0] == '*') continue;
		    if (building[lvl][0] == '.') {
		        q.push({lvl, 0});
		    } else if (building[lvl][0] == '$') {
		        ans++;
		    } else if (isupper(building[lvl][0])) {
		        if (k[tolower(building[lvl][0])] - 'a') q.push({lvl, 0});
		    } else if (islower(building[lvl][0])) {
		        q.push({lvl, 0});
		        k[building[lvl][0] - 'a'] = 1; // Found a key --> mark it true
		    }    
		    
		    // The right colunm
		    vis[lvl][w - 1] = 1; // Mark it visited
		    if (building[lvl][w - 1] == '*') continue;
		    if (building[lvl][w - 1] == '.') {
		        q.push({lvl, w - 1});
		    } else if (building[lvl][w - 1] == '$') {
		        ans++;
		    } else if (isupper(building[lvl][w - 1])) {
		        if (k[tolower(building[lvl][w - 1])] - 'a') q.push({lvl, w - 1});
		    } else if (islower(building[lvl][w - 1])) {
		        q.push({lvl, w - 1});
		        k[building[lvl][w - 1] - 'a'] = 1; // Found a key --> mark it true
		    } 
		}
		
		// BFS
		vector<pair<int, int>> lock; // Stores the positions of each locked doors
		while (!q.empty()){
		    pair<int, int> cur = q.front();
		    q.pop();
		    if (vis[cur.hight][cur.width] == 1) continue; // Already visited, skip
		    vis[cur.hight][cur.width] = 1;
		    if (isupper(building[cur.hight][cur.width])) { // When faced with a locked door
		        if (!k[tolower(building[cur.hight][cur.width])] - 'a') {
		            lock.push_back({cur.hight, cur.width}); // Put it on the waiting list of locked doors
		            continue; // skip if the key is missing
		        }
		    } else if (islower(building[cur.hight][cur.width])) { // When we found a key
		        if (k[building[cur.hight][cur.width] - 'a'] == 1) continue; // Skip, if we already had the key
		        k[building[cur.hight][cur.width] - 'a'] = 1; // Found a key --> mark it true
		        // Check if there is any available door to open
		        for (int i = 0; i < lock.size(); i++){
		            char alph = building[lock[i].hight][lock[i].width];
		            if (k[tolower(alph)] - 'a') {
		                vis[lock[i].hight][lock[i].width] = 1; // Mark it visited
		                q.push({lock[i].hight, lock[i].width}); // Push it into the queue
		            }
		        }
		    } else if (building[cur.hight][cur.width] == '$') ans++;
		    
		    for (int nxt = 0; nxt < 4; nxt++){
		        int nx = cur.hight + dx[nxt];
		        int ny = cur.width + dy[nxt];
		        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue; // OOB
		        if (vis[nx][ny] || building[nx][ny] == '*') continue; // Already visited or a wall
		        q.push({nx, ny});
		    }
		}
		cout << ans << '\n';
	}
	return 0;
}
