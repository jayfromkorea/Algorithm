#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, c;
	
	while (cin >> a >> b >> c){
		if (b - a > c - b) cout << b - a - 1 << '\n';
		else cout << c - b - 1 << '\n';
	}
}