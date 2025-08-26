#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, a;
	int freq[20000001] = {0};
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a;
		freq[a + 1000001]++;
	}
	for (int i = 0; i <= 2000001; i++){
		if(freq[i]){
			while(freq[i]--){
				cout << i - 1000001 << '\n';
			}
		}
	}
}