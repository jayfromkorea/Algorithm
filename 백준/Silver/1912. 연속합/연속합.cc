#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int t, num, sum, maximum;
    
    cin >> t;  // 수열의 길이 입력
    cin >> maximum; // 첫 번째 원소 입력
    sum = maximum;  // 초기 sum은 첫 번째 원소로 시작
    
    // 나머지 수열 처리
    for (int i = 1; i < t; ++i) {
        cin >> num;  // 수열의 각 원소를 읽음
        
        // sum에 num을 더한 값이 음수라면, 그 값을 버리고 새로 시작
        sum = max(num, sum + num);
        
        // sum이 max보다 크면, max를 갱신
        maximum = max(maximum, sum);
    }

    cout << maximum << endl;  // 가장 큰 부분합 출력
    return 0;
}
