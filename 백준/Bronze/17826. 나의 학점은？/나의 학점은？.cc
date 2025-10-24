#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int grades[51];
    int myGrade;
    string res;
    int rank = -1;

    // Input the grades for 50 students
    for (int i = 0; i < 50; i++) cin >> grades[i];
    
    // Input my grade
    cin >> myGrade;

    // Find my rank by comparing my grade to the grades list
    for (int i = 0; i < 50; i++) {
        if (grades[i] == myGrade) {
            rank = i + 1;  // Set the rank as the position of my grade
            break;  // Exit the loop once my grade is found
        }
    }

    // Assign grade based on rank
    if (rank <= 5) res = "A+";
    else if (rank <= 15) res = "A0";
    else if (rank <= 30) res = "B+";
    else if (rank <= 35) res = "B0";
    else if (rank <= 45) res = "C+";
    else if (rank <= 48) res = "C0";
    else if (rank <= 50) res = "F";

    // Output the result
    cout << res;
    
    return 0;
}
