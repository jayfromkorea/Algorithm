#include <iostream>
#include <vector>
using namespace std;

vector<int> failure(string& s){
	vector<int> f(s.size());
	int j = 0;
	for (int i = 1; i < s.size(); i++){
		while (j > 0 && s[i] != s[j]) j = f[j-1];
		if (s[i] == s[j]) f[i] = ++j;
	}
	
	return f;
}

int main() {
	string s; // The string 
	string t; // The target, substring we should find inside
	cin >> s >> t;
	int j = 0; // The index of the target(substring)
	vector<int> f = failure(s);
	for (int i = 0; i <= s.size(); i++){
		while (j > 0 && s[i] != t[j]) j = f[j-1];
		if (s[i] == t[j]) j++;
		if (j == t.size()) {
			cout << '1';
			return 0;
		}
	}
	cout << '0' << '\n';
	return 0;
}