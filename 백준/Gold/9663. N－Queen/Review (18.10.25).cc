#include <iostream>
using namespace std;

bool used1[40]; // "columns"
bool used2[40]; // "right diagnol" [0, 2n-2]
bool used3[40]; // "left diagnol" [1-n, n-1]
int n;
int count = 0;

void func(int row){
	if (row == n) { //when the last queen hits the bottom
		count++; // increment
		return; // reuturn
	}
	
	for (int col = 0; col < n; col++){
		if (used1[col] || used2[row + col] || used3[row - col + n - 1]) continue;
		used1[col] = 1;
		used2[row + col] = 1;
		used3[row - col + n - 1] = 1;
		func(row + 1);
		used1[col] = 0;
		used2[row + col] = 0;
		used3[row - col + n - 1] = 0;
	}
	
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	
	func(0);
	
	cout << count << '\n';
}
