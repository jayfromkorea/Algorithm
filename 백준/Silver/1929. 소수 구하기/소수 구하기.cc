#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Vector to mark whether numbers in [n, m] are prime
    vector<bool> v(m - n + 1, true); // Initialize all to true

    // 1 is not a prime number
    if (n == 1) v[0] = false;

    // Sieve of Eratosthenes from 2 to sqrt(m)
    for (int i = 2; i * i <= m; ++i) {
        // Calculate the starting point for marking multiples of i

        // Mark all multiples of i in the range [n, m] as not prime
        for (int j = i * i; j <= m; j += i) {
            if (j >= n) v[j - n] = false;
        }
    }

    // Output the primes in the range
    for (int i = 0; i < m - n + 1; ++i) {
        if (v[i]) {
            cout << i + n << '\n';
        }
    }

    return 0;
}
