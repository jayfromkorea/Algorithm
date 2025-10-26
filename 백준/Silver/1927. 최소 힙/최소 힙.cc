#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0;	// number of elements in heap

// Helper: move node up if smaller than its parent
void heapify_up(int idx) {
	while (idx > 1 && heap[idx] < heap[idx / 2]) {
		swap(heap[idx], heap[idx / 2]);
		idx /= 2;
	}
}

// Helper: move node down if greater than its children
void heapify_down(int idx) {
	while (true) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		int smallest = idx;

		if (left <= sz && heap[left] < heap[smallest]) smallest = left;
		if (right <= sz && heap[right] < heap[smallest]) smallest = right;

		if (smallest == idx) break;

		swap(heap[idx], heap[smallest]);
		idx = smallest;
	}
}

void push(int x) {
	heap[++sz] = x;
	heapify_up(sz);
}

int top() {
	if (sz == 0) return 0; // empty
	return heap[1];
}

void pop() {
	if (sz == 0) return;
	swap(heap[1], heap[sz--]);
	heapify_down(1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, p;
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> p;
		if (p == 0) {
			cout << top() <<'\n';
			pop();
		}
		else push(p);
	}
}