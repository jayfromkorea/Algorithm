#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

bool compare(string& a, string& b){
    if (a.size() != b.size())
        return a.size() < b.size();

    int sumA = 0, sumB = 0;
    for (char c : a) if (isdigit(c)) sumA += c - '0';
    for (char c : b) if (isdigit(c)) sumB += c - '0';

    if (sumA != sumB)
        return sumA < sumB;

    return a < b; // lexicographic
}

int main() {
    int n;
    string arr[51];

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n, compare);

    for (int i = 0; i < n; i++){
        cout << arr[i] << '\n';
    }
}
