#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string alp[7]; // An array to store Croatian alphabets
    int ans = s.size();
    alp[0] = "c=";
    alp[1] = "c-";
    alp[2] = "d-";
    alp[3] = "lj";
    alp[4] = "nj";
    alp[5] = "s=";
    alp[6] = "z=";
    int pos = 0;
    for (int i = 0; i < 6; i++){
        pos = 0;
        while (s.find(alp[i], pos) != string::npos){
            ans--;
            pos = s.find(alp[i], pos) + alp[i].size();
        }
    }
    pos = 0;
    while (s.find(alp[6], pos) != string::npos) {
        ans--;
        if (s.find(alp[6], pos) > 0 && s[s.find(alp[6], pos) - 1] == 'd') ans--;
        pos = s.find(alp[6], pos) + alp[6].size();
    }
    cout << ans << '\n';
}