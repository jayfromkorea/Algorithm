#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, a;
	int arr[12] = {0};
	cin >> n;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < 12; i++){
		arr[i] = arr[i] + arr[i - 1] + arr[i - 2] + arr[i - 3];
		}
	while(n--){
		cin >> a;
		
		cout << arr[a] << '\n';
	}
	return 0;
}