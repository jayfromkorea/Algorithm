#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define x first
#define y second

ll cross(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
    return (a.x - b.x) * (a.y - c.y) - (a.y - b.y) * (a.x - c.x);
}

bool onSegment(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c){
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    pair<ll, ll> a;
    pair<ll, ll> b;
    pair<ll, ll> c;
    pair<ll, ll> d;
    
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    
    ll d1 = cross(a, b, c);
    ll d2 = cross(a, b, d);
    ll d3 = cross(c, d, a);
    ll d4 = cross(c, d, b);
    
    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
        cout << 1 << '\n';
        return 0;
    }
    
    if (d1 == 0 && onSegment(a, b, c) || d2 == 0 && onSegment(a, b, d) || d3 == 0 && onSegment(c, d, a) || d4 == 0 && onSegment(c, d, b)){
        cout << 1 << '\n';
        return 0;
    }
    
    cout << 0 << '\n';
    return 0;
}