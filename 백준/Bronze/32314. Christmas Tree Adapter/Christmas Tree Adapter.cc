#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, w, v;
	// ampere = watt / volt
	
	cin >> a >> w >> v;
	
	if (a <= (w / v)) cout << 1 << '\n';
	else cout << 0 << '\n';
	
}