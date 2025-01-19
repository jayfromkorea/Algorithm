#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, in;
	
	vector<int> nums;
	
	cin >> n;
	while (n--){
		cin >> in;
		nums.push_back(in);
	}
	
	sort(nums.begin(), nums.end());
	
	for (int &a : nums){
		cout << a << "\n";
	}
}