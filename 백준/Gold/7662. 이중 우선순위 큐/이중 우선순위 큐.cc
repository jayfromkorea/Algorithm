#include <iostream>
#include <set>
using namespace std;

multiset<int> ms;

void func(int prompt, int op) {
    if (prompt == 'I') {
        ms.insert(op);
    } else {
        if (ms.empty()) return;  // revent runtime error

        if (op == 1) {
            // Delete the largest element
            auto it = prev(ms.end());
            ms.erase(it);
        } else {
            // Delete the smallest element
            auto it = ms.begin();
            ms.erase(it);
        }
    }
}

void EmptySet() {
    ms.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, k, op;
    char prompt;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> k;
        EmptySet();

        for (int j = 0; j < k; j++) {
            cin >> prompt >> op;
            func(prompt, op);
        }

        if (ms.empty())
            cout << "EMPTY\n";
        else
            cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
    }

    return 0;
}