#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, n, m, denom, numer;
	long long res;
	
	cin >> t;
	
	while (t--){
		res = 1;
		cin >> n >> m;
		denom = max(n, m - n) + 1;
		numer = 1;
		
		for (int i = m; i >= denom; i--){
			res *= i;
			res /= numer;
			numer++;
		}
		cout << res << endl;
	}
}