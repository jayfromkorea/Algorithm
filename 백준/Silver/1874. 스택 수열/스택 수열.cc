#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n, cur = 1, el; // "n" for number of elements, cur for current input count, el for each element 
    bool flag = true;
    stack<int> st;
    queue<char> q;

    cin >> n; // number of elements

    while (n--) { // run till it runs out of the input count
        cin >> el;
        
        // Ensure there are no problems with stack and push necessary elements to the stack
        while (st.empty() || st.top() < el) {
            st.push(cur);
            q.push('+');
            cur++;
        }

        if (st.top() == el) {
            st.pop();
            q.push('-');
        } else {
            flag = false;
            cout << "NO" << endl;
            break;
        }
    }

    // If flag is true, print the sequence of operations
    if (flag) {
        while (!q.empty()) {
            cout << q.front() << "\n";
            q.pop();
        }
    }

    return 0;
}
