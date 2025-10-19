#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool used[10];
vector<int> num;
int arr[10];
int n, m;

void func(int k){
	if (k == m) {
		for (int i = 0; i < m; i++){
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	
	for (int i = 0; i < n; i++){
		if (used[i]) continue;
		arr[k] = num[i];
		used[i] = 1;
		func(k + 1);
		used[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
    	cin >> a;
    	num.push_back(a);
    }
    
    sort(num.begin(), num.end());
    func(0);
}