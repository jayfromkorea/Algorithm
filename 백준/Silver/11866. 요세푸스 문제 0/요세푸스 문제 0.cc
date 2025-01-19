#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	int n, k, t;
	vector<int> ppl;
	deque<int> ans;
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		ppl.push_back(i);
	}
	cin >> k;
	int index = 0;
	while (!ppl.empty()){
		index = (index + k - 1) % ppl.size();
		ans.push_back(ppl[index]);
		ppl.erase(ppl.begin() + index);
	}
	cout << "<" << ans.front();
	ans.pop_front();
	while (!ans.empty()){
		cout << ", " << ans.front();
		ans.pop_front();
	}
	cout << ">";
	
}