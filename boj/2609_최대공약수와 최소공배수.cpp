#include <iostream>
using namespace std;

// 유클리드 호제법
// a > b인 두 자연수 a, b에 대해서
// a를 b로 나눈 나머지, 즉 a % b를 r이라고 했을 때, 
// a와 b의 최대공약수는 b와 r의 최대공약수와 같다.
// 이 과정을 계속 반복하여 나머지(r)가 0이 되었을 때,
// 그 때의 나누는 수(b)가 a와 b의 최대공약수가 된다.

// 참고 https://velog.io/@shasha/C-%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C-%ED%98%B8%EC%A0%9C%EB%B2%95-%EC%B5%9C%EB%8C%80%EA%B3%B5%EC%95%BD%EC%88%98-%EA%B5%AC%ED%95%98%EA%B8%B0
// 최소공배수는 a * b / (최대공약수)

// 재귀로 표현
int func(int mx, int mn) {
	if(mn == 0)
	return mx;

	return func(mn, mx % mn);
}

int main() {
	int n1, n2;

	cin >> n1 >> n2;
	int res = func(max(n1, n2), min(n1, n2));
	cout << res << '\n';
	cout << n1 * n2 / res;

	return 0;
}