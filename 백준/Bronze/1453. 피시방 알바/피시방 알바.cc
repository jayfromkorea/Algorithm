#include <iostream>
using namespace std;

bool occ[101]; // Checks if occupied

int main() {
	int n;
	int cust;
	int ans = 0;
	
	cin >> n;
	while (n--){
		cin >> cust;
		if (occ[cust]) ans++;
		else occ[cust] = 1;
	}
	
	cout << ans << '\n';
}