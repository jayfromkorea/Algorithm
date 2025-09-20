#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, p;
	
	
	cin >> n;
	int count = n;
	
	
	
	while (n--){
		cin >> p;
		
		if (p == 1) {
			count--;
			//cout << p << ' ' << count << '\n';
			continue;
		}
		
		for (int i = 2; i*i <= p; i++){
			if (p % i*i == 0) {
				count--;
				//cout << p << ' ' << count << '\n';
				break;
			}
		}
	}
	
	cout << count << '\n';
}