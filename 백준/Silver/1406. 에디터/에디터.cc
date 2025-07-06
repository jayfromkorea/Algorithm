#include <iostream>
#include <list>
using namespace std;

int main() {
	list<char> L;
	string s;
	int m; //the number of commands
	char op, t;
	
	cin >> s;
	for (char l : s){
		L.push_back(l);
	}
	auto ptr = L.end();
	
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> op;
		
		
		if (op == 'L' && ptr != L.begin()){
			ptr--;
			//cout << "L triggered" << "\n";
		} else if (op == 'D' && ptr != L.end()){
			ptr++;
			//cout << "D triggered" << "\n";
		} else if (op == 'B' && ptr != L.begin()){
			ptr--;
			ptr = L.erase(ptr);
			//cout << "B triggered" << "\n";
		} else if(op == 'P'){
			cin >> t;
			L.insert(ptr, t);
			//cout << "P triggered" << "\n";
		}
	}
	for (char ans : L){
		cout << ans;
	}
	return 0;
}