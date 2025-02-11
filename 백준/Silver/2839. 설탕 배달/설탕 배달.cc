#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, count = 0;
	
	cin >> n;
	while (n > 0){
		if (n % 5 == 0){
			count += (n / 5);
			cout << count << endl;
			return 0;
		}
		
		n -= 3;
		count++;
		if (n == 0){
			cout << count << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
}