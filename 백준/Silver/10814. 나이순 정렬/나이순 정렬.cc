#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, age;
	string name;
	
	vector<pair<int, string>> v;
	
	cin >> n;
	 while (n--){
	 	cin >> age >> name;
	 	v.push_back({age, name});
	 }
	 
	stable_sort(v.begin(), v.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
    	return a.first < b.first;
	});

	 
	 for (const auto& p : v){
	 	cout << p.first << " " << p.second << "\n";
	 }
}