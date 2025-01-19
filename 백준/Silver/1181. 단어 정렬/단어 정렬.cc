#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comparator(const string &a, const string &b) {
    if (a.length() == b.length()) {
        return a < b; 
    }
    return a.length() < b.length(); 
}

int main() {
    int n;
    string in;
    
    vector<string> w;
    
    cin >> n;
    
    while (n--) {
        cin >> in;
        
        if (find(w.begin(), w.end(), in) == w.end()) {
            w.push_back(in);
        }
    }
    
    
    sort(w.begin(), w.end(), comparator);
    
   
    for (const string &word : w) {
        cout << word << "\n";
    }
    
    return 0;
}
