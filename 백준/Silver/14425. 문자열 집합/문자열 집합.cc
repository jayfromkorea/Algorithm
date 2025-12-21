#include <iostream>
using namespace std;

const int MX = 10000 * 500 + 5;
int nxt[MX][26];
bool last[MX];
int ROOT = 1;
int unused = 2;

int c2i(char c){
	return c - 'a';
}

void insert(string& s){
	int cur = ROOT;
	for (char c : s){
		if (nxt[cur][c2i(c)] == -1) nxt[cur][c2i(c)] = unused++;
		cur = nxt[cur][c2i(c)];
	}
	last[cur] = true;
	return;
}

bool find(string& s){
	int cur = ROOT;
	for (char c : s){
		if (nxt[cur][c2i(c)] == -1){
			return false;
		}
		cur = nxt[cur][c2i(c)];
	}
	return last[cur];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 0; i < MX; i++){
		fill(nxt[i], nxt[i] + 26, -1);
	}
	
	int n, m;
	cin >> n >> m;
	while (n--){
		string s;
		cin >> s;
		insert(s);
	}
	int ans = 0;
	while (m--){
		string s;
		cin >> s;
		if (find(s)) ans++;
	}
	
	cout << ans << '\n';
}