#include <iostream>
using namespace std;

char l[30]; // an array for left child
char r[30]; // an array for right child
int n;

void pre(char a){
	cout << a;
	if (l[a - 'A'] != '.') pre(l[a - 'A']);
	if (r[a - 'A'] != '.') pre(r[a - 'A']);
}

void in(char a){
	if (l[a - 'A'] != '.') in(l[a - 'A']);
	cout << a;
	if (r[a - 'A'] != '.') in(r[a - 'A']);
}

void post(char a){
	if (l[a - 'A'] != '.') post(l[a - 'A']);
	if (r[a - 'A'] != '.') post(r[a - 'A']);
	cout << a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	
	//input
	char par, left, right;
	for (int i = 1; i <= n; i++) {
		cin >> par >> left >> right;
		l[par - 'A'] = left;
		r[par - 'A'] = right;
	}
	
	pre('A');
	cout << '\n';
	in('A');
	cout << '\n';
	post('A');
	cout << '\n';
	
}