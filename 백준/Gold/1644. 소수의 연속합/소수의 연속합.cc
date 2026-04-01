#include <iostream>
#include <vector>
using namespace std;

vector<int> prime; // A vector to store prime numbers

void sieve(int a){
    vector<bool> p(a + 5, true); // A vector to store if the integer is PRIME
    p[1] = 0;
    for (int i = 1; i <= a; i++){
        if (!p[i]) continue; // If it's sieved already, skip
        for (int j = 2*i; j <= a; j += i){
            p[j] = 0;
        }
    }
    
    // Store prime numbers
    for (int i = 1; i <= a; i++) {
        if (p[i]) prime.push_back(i);
    }
    
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    if (n < 2) { // When n == 1, it causes OOB later in two pointer process
        cout << 0 << '\n';
        return 0;
    }
    
    sieve(n);
    
    // Two pointer method
    int left = 0; 
    int right = 0;
    int ans = 0;
    long long sum = prime[0];
    while (left <= right && right < prime.size()){
        if (sum == n) {
            ans++;
            sum -= prime[left++];
        } else if (sum < n) {
            ++right;
            if (right >= (int)prime.size()) break;
            sum += prime[right];
        } else {
            sum -= prime[left++];
        }
    }
    
    cout << ans << '\n';
}