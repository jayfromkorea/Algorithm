#include <iostream>
using namespace std;

int main() {
    for (int n = 10; n <= 99; n++) {
        int a = n / 10;   // 십의 자리
        int b = n % 10;   // 일의 자리

        // 숫자 8이 포함되면 제외
        if (a == 8 || b == 8) continue;

        // 뒤집은 수
        int rev = b * 10 + a;

        // 뒤집은 수가 4의 배수인지
        if (rev % 4 != 0) continue;

        // 자리수 합이 6의 배수인지
        if ((a + b) % 6 != 0) continue;

        // 모든 조건 만족
        cout << n << '\n';
    }

    return 0;
}
