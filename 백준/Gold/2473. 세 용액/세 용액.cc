#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++) cin >> v[i];
    
    sort(v, v + n);
    
    long long mini = 3000000001;
    int a, b, c;
    
    for (int i = 0; i < n - 2; i++){
        int lo = i + 1, hi = n - 1;
        while (lo < hi){
            long long sum = (long long)v[i] + v[lo] + v[hi];
            if (abs(sum) < abs(mini)){
                mini = sum;
                a = v[i]; b = v[lo]; c = v[hi];
            }
            if (sum < 0) lo++;
            else if (sum > 0) hi--;
            else goto done; // sum == 0, can't get better
        }
    }
    done:
    cout << a << ' ' << b << ' ' << c << '\n';
}