#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	cin.tie(0),ios::sync_with_stdio(0);
	
	int n, m;
	long  temp1, temp2;
	
	vector<int> nums(20000001, 0);
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> temp1;
		temp1 += 10000000;
		nums[temp1]++;
	}
	
	cin >> m;
	
	for (int i = 0; i < m; i++){
		cin >> temp2;
		temp2 += 10000000;
		cout << nums[temp2] << " ";
	}
}