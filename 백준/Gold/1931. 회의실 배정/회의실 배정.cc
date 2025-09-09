#include <iostream>
#include <algorithm>
#define end first
#define start second
using namespace std;

int main() {
	pair<int, int> m[100001];
	int n, a, b;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		m[i] = {b, a};
	}
	
	sort(m, m + n);
	
	int bdry = m[0].end;
	int count = 1;
	for (int i = 1; i < n; i++){
		if (m[i].start >= bdry){
			count++;
			bdry = m[i].end;
		}
	}
	
	cout << count << '\n';
}