#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
using ll = long long;

const int MAX = 4005;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    ll a[MAX];
    ll b[MAX];
    ll c[MAX];
    ll d[MAX];
    
    vector<ll> ab;
    vector<ll> cd;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 4; j++){
            if (j == 0) cin >> a[i];
            else if (j == 1) cin >> b[i];
            else if (j == 2) cin >> c[i];
            else cin >> d[i];
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ll sum1 = a[i] + b[j];
            ll sum2 = c[i] + d[j];
            ab.push_back(sum1);
            cd.push_back(sum2);
        }
    }
    
    sort(cd.begin(), cd.end());
    ll cnt = 0;
    for (int i = 0; i < n*n; i++){
        ll target = -ab[i];
        int lo = lower_bound(cd.begin(), cd.end(), target) - cd.begin();
        int hi = upper_bound(cd.begin(), cd.end(), target) - cd.begin();
        cnt += hi - lo;
    }
    
    cout << cnt << '\n';
}