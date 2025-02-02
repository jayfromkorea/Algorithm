#include <iostream>
using namespace std;

int main() {
	
	cin.tie(0),ios::sync_with_stdio(0);
	
	int m, value;
	
	string command;
	
	int arr[21] = {0};
	
	cin >> m;
	
	while (m--){
		cin >> command;
		
		if (command == "add"){
			cin >> value;
			if (arr[value] != 1){
				arr[value]++;	
			}
		} else if (command == "remove"){
			cin >> value;
			if (arr[value] != 0){
				arr[value] = 0;
			}
			
		} else if (command == "check"){
			cin >> value;
			cout << arr[value] << "\n";
		} else if (command == "toggle"){
			cin >> value;
			if (arr[value] == 0){
				arr[value]++;
			} else {
				arr[value]--;
			}
		} else if (command == "all"){
			for (int i = 1; i <= 20; i++){
				arr[i] = 1;
			}
		} else if (command == "empty"){
			for (int i = 1; i <= 20; i++){
				arr[i] = 0;
			}
		}
	}
}