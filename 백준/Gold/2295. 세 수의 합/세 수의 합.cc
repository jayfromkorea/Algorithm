#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> v; // the entire value
vector<int> t; // combinations of every two pair


void two(){
	int sum;
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			sum = v[i] + v[j];
			t.push_back(sum);
		}
	}
	sort(t.begin(), t.end());
}

int func(){
	for (int i = n - 1; i > 0; i--){
		for (int j = 0; j < i; j++){
			if (binary_search(t.begin(), t.end(), v[i] - v[j])){
				return v[i];
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int p;
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> p;
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	//erase.(unique(v.begin(), v.last()), v.end());
	
	two();
	cout << func() << '\n';
	
	return 0;
}