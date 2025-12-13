#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	string str = to_string(n);
	int size = str.size();
	int k = 1; // The K-th number
	int i = 0;
	int kl = 1; // The length of k
	while (i < size){
		string match = to_string(k);
		if (str.substr(i, kl) != match) {
			cout << -1;
			return 0;
		}
		i += kl; // i = i + kl
		k++;
		if (to_string(k).size() > kl){ // If the number of digits of K increments
			kl++;
		}
	}
	cout << k - 1 << '\n';
	return 0;
}