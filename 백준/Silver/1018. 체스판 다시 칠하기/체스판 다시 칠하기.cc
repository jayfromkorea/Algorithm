#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string WB[2] = {"WBWBWBWB", "BWBWBWBW"};
string BW[2] = {"BWBWBWBW", "WBWBWBWB"};
string columns[51]; // an array of strings that would store each line

// Function to count the changes required to match the WB pattern
int WBcount(int a, int b){
    int count = 0;
    for (int i = 0; i < 8; i++) {  // iterate over 8 rows
        for (int j = 0; j < 8; j++) {  // iterate over 8 columns
            if (columns[a + i][b + j] != WB[(i % 2)][j]) {
                count++;
            }
        }
    }
    return count;
}

// Function to count the changes required to match the BW pattern
int BWcount(int a, int b){
    int count = 0;
    for (int i = 0; i < 8; i++) {  // iterate over 8 rows
        for (int j = 0; j < 8; j++) {  // iterate over 8 columns
            if (columns[a + i][b + j] != BW[(i % 2)][j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, m, minCount = 65, Wcount = 65, Bcount = 65; // n: horizontal, m: vertical
    string each_line;

    cin >> n >> m;

    // Input the grid of lines
    for (int i = 0; i < n; i++){
        cin >> each_line;
        columns[i] = each_line; // storing each line
    }

    // Loop through all possible 8x8 sub-grids and calculate the minimum number of changes
    for (int i = 0; i + 7 < n; i++) {
        for (int j = 0; j + 7 < m; j++) {
            // Calculate the count of changes for both patterns WB and BW
            Wcount = WBcount(i, j);
            Bcount = BWcount(i, j);
            
            // Find the minimum count
            minCount = min(minCount, min(Wcount, Bcount));
        }
    }

    cout << minCount << "\n";
}
