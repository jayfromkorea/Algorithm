#include <iostream>
#include <vector>
using namespace std;

int n, a, b, c, num_of_infections = 0;
	
vector<int> connec[101];
	
bool is_visited[101] = {false, };

void Search (int current){
		for (int j = 0; j < connec[current].size(); j++){
			int next = connec[current][j];
			
			if (!is_visited[next]){
				num_of_infections++;
				is_visited[next] = true;
				Search(next);
			}
		}
	}

int main() {
	
	cin >> n >> c;
	
	for (int i = 0; i < c; i++){
		cin >> a >> b;
		connec[a].push_back(b);
		connec[b].push_back(a);
	}
	
	is_visited[1] = true;
	Search(1);
	
	cout << num_of_infections;
	
	
	
}