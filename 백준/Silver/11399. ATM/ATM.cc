#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, p, cur = 0, fin = 0;
	
	vector<int> time;
	vector<int> res;
	
	cin >> n;
	
	while(n--){
		cin >> p;
		time.push_back(p);
	}
	
	sort(time.begin(), time.end());
	
	for(int i = 0; i < time.size(); i++){
		cur += time[i];
		//cout << "current cur: " << cur << "\n";
		res.push_back(cur);
	}
	for (int ans : res){
		fin += ans;
		//cout << "current value: " << fin << "\n";
	}
	
	cout << fin << "\n";
}