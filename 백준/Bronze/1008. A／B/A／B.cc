#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	
	cin >> a >> b;
	
	cout << a / b << ".";
	
	int cur = a % b;
	
	for (int i = 0; i < 9; i++){
		if (cur == 0) return 0;
		cur *= 10;
		cout << cur / b;
		// Yes!!
		//Finally!!
		cur %= b;
	}
	
}

