#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	
	getline(cin, s);
	
	int last = s.length() - 1;
	
	if (s[0] != '"') {
		cout << "CE";
		return 0;
	} else if (s[last] != '"') {
		cout << "CE";
		return 0;
	} else if (s.length() < 3) {
		cout << "CE";
		return 0;
	}
	cout << s.substr(1, last - 1);   
	
	
}