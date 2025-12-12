#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	
	long long ans = 1;
	long long base = a % c;
	
	while (b > 0){
		if (b % 2 == 1){ // If b is an odd number
			ans = (ans * base) % c;
			b--;
		}
		base = base * base % c;
		b /= 2;
	}
	
	cout << ans << '\n';
}