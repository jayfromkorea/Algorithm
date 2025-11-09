#include <iostream>
using namespace std;

int p[1000005];

int main() {
	int a, b, c, d, e;
	
	cin >> a >> b >> c >> d >> e;
	
	int sum = a*a + b*b + c*c + d*d + e*e;
	int ans = sum % 10;
	cout << ans << '\n';
}