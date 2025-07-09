#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; //n for the size
	string opt;
	queue<int> q;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> opt;
		
		if (opt == "push"){
			cin >> m;
			q.push(m);
		} else if(opt == "pop"){
			if (q.empty()){
				cout << -1 << "\n";
			} else {
				cout << q.front() << "\n";
				q.pop();
			}
		} else if(opt == "size"){
			cout << q.size() << "\n";
		} else if(opt == "front"){
			if (q.empty()){
				cout << -1 << "\n";
			} else {
				cout << q.front() << "\n";
			}
		} else if (opt == "back"){
			if (q.empty()){
				cout << -1 << "\n";
			} else {
				cout << q.back() << "\n";
			}
		} else if (opt == "empty"){
			cout << q.empty() << "\n";
		}
	}
}