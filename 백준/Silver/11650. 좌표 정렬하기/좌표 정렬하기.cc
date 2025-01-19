#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, x, y;
	vector<pair<int, int>> cor;
	
	cin >> n;
	
	while (n--){
		cin >> x >> y;
		cor.push_back({x, y});
	}
	
	sort(cor.begin(), cor.end());
	for (const auto& p : cor){
		cout << p.first << " " << p.second << "\n";
	}
}