#include <iostream>
#include <algorithm>
using namespace std;

int p[100005]; // An array that stores the parent gate of a subarray of gate(s)

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]); // path compression
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int g, planes;
    cin >> g >> planes;
    
    // The gates that point to itself are not occupied, whereas pointing to '0' meaning every gate occupied
    for (int i = 0; i <= g; i++) p[i] = i;
    
    int gi;
    int ans = 0;
    for (int i = 0 ; i < planes; i++){
        cin >> gi;
        gi = find(gi);
        if (gi == 0) break;
        p[gi] = find(gi - 1); // As the gate 'gi' holds an aircraft, change the root gate to the one that the one ahead is pointing to
        ans++; // Increase the num of aircrafts being docked
    }
    cout << ans << '\n';
    return 0;
}