#include <iostream>
#include <map>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	map<string, int> count;
	deque<string> obs;
	int n, m, counter = 0;
	string name;
	
	cin >> n >> m;
	
	while (n--){
		cin >> name;
		
		count[name]++;
	}
	
	while (m--){
		cin >> name;
		
		count[name]++;
		if (count[name] >= 2){
			obs.push_back(name);
			counter++;
		}
	}
	sort(obs.begin(), obs.end());
	cout << counter << "\n";
	while(!obs.empty()){
		cout << obs.front() << "\n";
		obs.pop_front();
	}
}