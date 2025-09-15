#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    pair<string, string> data[100001];  // Pair: (website, password)

    for (int i = 0; i < n; i++) {
        cin >> data[i].first >> data[i].second;
    }

    // Sort the array by website name
    sort(data, data + n);

    // Query and use binary search
    string query;
    for (int i = 0; i < m; i++) {
        cin >> query;

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (data[mid].first == query) {
                cout << data[mid].second << '\n';
                break;
            } else if (data[mid].first < query) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return 0;
}
