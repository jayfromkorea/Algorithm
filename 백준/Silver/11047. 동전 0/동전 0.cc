#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int type[11];
    for (int i = 0; i < n; i++) cin >> type[i];

    int count = 0;
    for (int i = n - 1; i >= 0; i--) {  // start from largest coin
        if (type[i] <= k) {
            count += k / type[i];  // use as many of this coin as possible
            k %= type[i];          // reduce remaining amount
        }
    }

    cout << count << '\n';
    return 0;
}
