#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int extra = 0;
	string target = "50";
	for (int i = 1; i <= n; i++){
		string str = to_string(i);
		auto pos = str.find(target);
		if (pos != string::npos) extra++;
	}
	
	// If n itself contains "50", decrement to get correct output
	string str = to_string(n);
	auto pos = str.find(target);
	if (pos != string::npos) extra--;
	
	
	cout << n + extra << '\n';
}