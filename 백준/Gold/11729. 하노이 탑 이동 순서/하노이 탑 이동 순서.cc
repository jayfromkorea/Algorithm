#include <iostream>
using namespace std;

int Hanoi(int start, int goal, int rest);
int steps = 0;

int Hanoi(int start, int rest, int goal, int size){
	//int a = 1, b = 2, c = 3;
	int a = start;
	int b = rest;
	int c = goal;
	
	if (size == 1){
		cout << a << " " << c << '\n';
		steps++;
		return steps;
	}
	
	
	Hanoi(a, c, b, size - 1);
	cout << start << " " << goal << '\n';
	Hanoi(b, a, c, size - 1);
	steps++;
	return steps;
	
}

int main() {
	int counts = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		counts = 2*counts + 1;
	}
	cout << counts << '\n';
	Hanoi(1, 2, 3, n);
	
}