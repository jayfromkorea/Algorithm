#include <iostream>
using namespace std;

int arr[21];
int n, s, count = 0;

void func (int cur, int total){
	if (cur == n){
		if (total == s) count++;
		return;
	}
	
	func(cur + 1, total + arr[cur]);
	func(cur + 1, total);
}

int main() {
	cin >> n >> s;
	
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	func(0, 0);
	if (s == 0) count--;
	cout << count << '\n';
}