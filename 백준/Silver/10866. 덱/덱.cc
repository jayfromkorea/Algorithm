#include <iostream>
using namespace std;

int main() {
	const int MX = 1000005;
	int n, m, dat[2*MX + 1], head = MX, tail = MX;
	string opt;
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> opt;
		if (opt == "push_front"){
			cin >> m;
			dat[--head] = m;
		} else if (opt == "push_back"){
			cin >> m;
			dat[tail++] = m;
		} else if(opt == "pop_front"){
			if (head == tail){
				cout << -1 << '\n';
			} else {
				cout << dat[head++] << '\n';
			}
		} else if(opt == "pop_back"){
			if (head == tail){
				cout << -1 << '\n';
			} else {
				cout << dat[tail - 1] << '\n';
				tail--;
			}
		} else if(opt == "size"){
			cout << tail - head << '\n';
		} else if(opt == "empty"){
			(head == tail) ? cout << 1 << '\n': cout << 0 << '\n';
		} else if(opt == "front"){
			if (head == tail){
				cout << -1 << '\n';
			} else {
				cout << dat[head] << '\n';
			}
		} else if(opt == "back"){
			if (head == tail){
				cout << -1 << '\n';
			} else {
				cout << dat[tail - 1] << '\n';
			}
		}
	}
}