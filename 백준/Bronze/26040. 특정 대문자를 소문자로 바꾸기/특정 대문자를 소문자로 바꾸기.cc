#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    vector<char> cap;
    string s;
    
    cin >> s;
    char a;
    while (cin >> a) {
        cap.push_back(a);
    }
    
    for (char e : s){
        char temp = e;
        for (char c : cap){
            if (e == c) {
                temp = tolower(c);
                break;
            }
        }
        cout << (char)temp;
    }
    
    return 0;
}