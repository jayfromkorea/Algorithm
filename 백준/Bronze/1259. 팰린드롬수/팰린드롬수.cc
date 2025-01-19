#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int li = 0, size = 0, ri;
	bool flag = true;
	string in;
	
	cin >> in;
	
	while (in != "0") {
		if (in.length() <= 1){
			cout << "yes" << "\n";
		} else {
			li = 0;
			ri = in.length() - 1;
			flag = true;
			while (li < ri) {
				if(in[li] != in[ri]) {
					flag = false;
					break;
				}
				li++;
				ri--;
			}
			if (flag){
				cout << "yes" << "\n";
			} else {
				cout << "no" << "\n";
			}
		}
		cin >> in;
	}
	
}