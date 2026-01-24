#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	string arr[505];
	int ans = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++){
	    string s = arr[i];
	    for (int j = 0; j < s.length() - 1; j++){
	        string ss = s.substr(j, 2);
	        if (ss == "01" || ss == "OI") {
	            ans++;
	            break;
	        }
	    }
	}
	cout << ans << '\n';
}	