#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int used[10];
vector<int> v;
int arr[10];

void func(int cnt){
	if (cnt == m){
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	int x = -1;
	for (int j = 0; j < v.size(); j++){
		if (!used[j] && v[j] != x){
			arr[cnt] = v[j];
			x = v[j];
			used[j] = true;
			func(cnt + 1);
			used[j] = false;
		}
	}
}


int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    
	cin >> n >> m;
	
	int p;
	while (n--){
		cin >> p;
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	
	func(0);
}