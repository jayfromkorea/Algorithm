#include <iostream>
using namespace std;

int main() {
	int n, a=0;
	string c;
	char t;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		for (int j = 0; j < c.length() ; j++){
			if (a == -1) {
				break;
			}
			if (c[j] == '('){
				a++;
			} else {
				a--;
			}
		}
		if (a == 0) {
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";
		}
		a = 0;
	}
	
}