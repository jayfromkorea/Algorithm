#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int cur;
	cin >> cur;
	if (cur != 1 && cur != 8) {
		cout << "mixed" << '\n';
		return 0;
	}
	
	if (cur == 1){
		int p = 2;
		for (int i = 1; i < 8; i++){
			cin >> cur;
			if (cur != p){
				cout << "mixed" << '\n';
				return 0;
			}
			p++;
		}
		cout << "ascending" << '\n';
		return 0;
	} else {
		int p = 7;
		for (int i = 1; i < 8; i++){
			cin >> cur;
			if (cur != p){
				cout << "mixed" << '\n';
				return 0;
			}
			p--;
		}
		cout << "descending" << '\n';
		return 0;
	}
}