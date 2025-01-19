#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, t;
	
	queue<int> nums;
	
	cin >> n;
	for (int i = 0; i < n; i++){
		 nums.push(i + 1);
	}
	
	while (nums.size() > 1){
		nums.pop();
		t = nums.front();
		nums.pop();
		nums.push(t);
	}
	cout << nums.front();
	
}