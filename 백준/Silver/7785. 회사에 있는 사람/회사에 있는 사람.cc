#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	unordered_set<string> s;
	vector<string> v;
	int n;
	string a, b;
	cin >> n;
	
	while (n--){
		cin >> a >> b;
		if (b == "enter") s.insert(a);
		else s.erase(a);
	}
	
	for (string x : s) {
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    
    for (int i = v.size()-1; i >= 0; i--) cout << v[i] << '\n';
}