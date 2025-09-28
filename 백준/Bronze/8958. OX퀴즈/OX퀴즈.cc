#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	string s;
	
	cin >> n;
	
	
	while (n--){
		int streak = 0;
		int ans = 0;
		cin >> s;
		for (int i = 0; i < s.length(); i++){
			if (s[i] == 'O') streak++;
			else streak = 0;
			ans += streak;
		}
		cout << ans << '\n';
	}
}