using namespace std;
#include <iostream>
#include <map>

using ll = long long;
ll n, p, q;
map<ll, ll> dp;

ll func(ll x){
    if (dp[x] != 0) return dp[x];
    if (x < 1) return dp[x] = 1;
    return dp[x] = func(x/p) + func(x/q);
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	
    cin >> n >> p >> q;
    cout << func(n) << '\n';
}