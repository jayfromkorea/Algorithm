#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    
	map<string, int> mp;
	int n, m;
	string name, tar;
	cin >> n >> m;
	string arr[n+1];
	
	for (int i = 1; i < n+1; i++) {
		cin >> arr[i];
		mp[arr[i]] = i;
	}
	
	for (int i = 0; i < m; i++){
		cin >> tar;
		if (isdigit(tar[0])) cout << arr[stoi(tar)] << '\n';
		else cout << mp[tar] << '\n';
	}
}