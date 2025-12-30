#include <iostream>
using namespace std;

bool occ[101]; // Checks if occupied

int main() {
	int n;
	cin >> n;
	if (!(n % 4)) cout << 2;
	else if (!(n % 2)) cout << 1;
	else cout << 0 << '\n';
}