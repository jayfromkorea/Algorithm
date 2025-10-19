#include <iostream>
using namespace std;

//bool used[10];
int arr[10];
int n, m;

void func(int k, int last){
	if (k == m) {
		for (int i = 0; i < m; i++){
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	
	for (int i = 1; i <= n; i++){
		//if (used[i]) continue;
		arr[k] = i;
		//used[i] = 1;
		func(k + 1, i);
		//used[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    func(0, 0);
}