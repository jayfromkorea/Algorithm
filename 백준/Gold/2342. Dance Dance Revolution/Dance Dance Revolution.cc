#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int total;
int dp[100005][5][5]; // [The number of the key to press][the location of the left][the loc of the right]
int num[100005]; // The sequence to store keys to press

int moveCost(int from, int to) { // The moving cost
    if (from == to) return 1;
    if (from == 0) return 2;
    if (abs(from - to) == 2) return 4;  // Accros
    return 3;  // Adjacent
}

int func(int p, int l, int r) {
    if (p == total) return 0;
    
    int& ret = dp[p][l][r];
    if (ret != -1) return ret;
    
    int target = num[p];
    ret = 1e7;
    
    // Make sure the two feet don't step on the same tile
    if (target != r)
        ret = min(ret, moveCost(l, target) + func(p+1, target, r));
    
    // Make sure the two feet don't step on the same tile
    if (target != l)
        ret = min(ret, moveCost(r, target) + func(p+1, l, target));
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    
    int a;
    total = 0;
    while(cin >> a) {
        if (a == 0) break;
        num[total] = a;
        total++;
    }
    
    cout << func(0, 0, 0) << '\n';
}