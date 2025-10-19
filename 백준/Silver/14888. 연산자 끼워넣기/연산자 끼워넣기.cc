#include <iostream>
#include <climits>
using namespace std;

int n;
int nums[15];
int opCount[4];  // +, -, *, /
int maxResult = INT_MIN;
int minResult = INT_MAX;

void dfs(int idx, int current) {
    if (idx == n) {
        maxResult = max(maxResult, current);
        minResult = min(minResult, current);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (opCount[i] == 0) continue;
        opCount[i]--;

        int next = current;
        if (i == 0) next += nums[idx];
        else if (i == 1) next -= nums[idx];
        else if (i == 2) next *= nums[idx];
        else {
            if (next < 0) next = -(-next / nums[idx]);
            else next /= nums[idx];
        }

        dfs(idx + 1, next);
        opCount[i]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < 4; i++) cin >> opCount[i];

    dfs(1, nums[0]);

    cout << maxResult << '\n' << minResult << '\n';
}
