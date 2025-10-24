#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int num;
	
	cin >> num;
	
	(num / 10000) == 555 ? cout << "YES" : cout << "NO";
	
}