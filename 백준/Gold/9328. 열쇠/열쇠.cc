// Fixed and cleaned up by the help of chatgpt

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <deque>
#include <queue>
#include <cctype>
using namespace std;
#define hight first
#define width second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t; // ✅ FIX 1

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (t--) {
        int ans = 0;
        int h, w;
        cin >> h >> w; // ✅ FIX 2 (order)

        bool vis[105][105] = {false};
        bool k[26] = {false}; // ✅ size 26

        queue<pair<int, int>> q;
        deque<string> building;

        string row;
        for (int i = 0; i < h; i++) {
            cin >> row;
            building.push_back(row); // (push_back is fine)
        }

        string keys;
        cin >> keys;
        if (keys != "0") {
            for (char c : keys) {
                k[c - 'a'] = 1;
            }
        }

        // doors separated by type ✅ FIX 7
        vector<pair<int,int>> doors[26];

        // 🔥 Start from edges (same structure, but FIXED logic)
        for (int p = 0; p < w; p++) {
            // bottom
            char c = building[0][p];
            if (c != '*') {
                if (isupper(c) && !k[c - 'A']) {
                    doors[c - 'A'].push_back({0, p});
                } else {
                    q.push({0, p});
                    vis[0][p] = 1;
                }
            }

            // top
            c = building[h - 1][p];
            if (c != '*') {
                if (isupper(c) && !k[c - 'A']) {
                    doors[c - 'A'].push_back({h - 1, p});
                } else {
                    q.push({h - 1, p});
                    vis[h - 1][p] = 1;
                }
            }
        }

        for (int lvl = 1; lvl < h - 1; lvl++) {
            // left
            char c = building[lvl][0];
            if (c != '*') {
                if (isupper(c) && !k[c - 'A']) {
                    doors[c - 'A'].push_back({lvl, 0});
                } else {
                    q.push({lvl, 0});
                    vis[lvl][0] = 1;
                }
            }

            // right
            c = building[lvl][w - 1];
            if (c != '*') {
                if (isupper(c) && !k[c - 'A']) {
                    doors[c - 'A'].push_back({lvl, w - 1});
                } else {
                    q.push({lvl, w - 1});
                    vis[lvl][w - 1] = 1;
                }
            }
        }

        // BFS
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            char c = building[cur.hight][cur.width];

            // 💰 document
            if (c == '$') ans++;

            // 🔑 key
            if (islower(c)) {
                int idx = c - 'a';
                if (!k[idx]) {
                    k[idx] = 1;

                    // unlock stored doors
                    for (auto &d : doors[idx]) {
                        if (!vis[d.hight][d.width]) {
                            vis[d.hight][d.width] = 1;
                            q.push(d);
                        }
                    }
                }
            }

            for (int nxt = 0; nxt < 4; nxt++) {
                int nx = cur.hight + dx[nxt];
                int ny = cur.width + dy[nxt];

                // ✅ FIX 4 (bounds)
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (vis[nx][ny]) continue;

                char nc = building[nx][ny];
                if (nc == '*') continue;

                // 🚪 door
                if (isupper(nc)) {
                    int idx = nc - 'A';
                    if (!k[idx]) {
                        doors[idx].push_back({nx, ny});
                        continue;
                    }
                }

                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }

        cout << ans << '\n';
    }
    return 0;
}