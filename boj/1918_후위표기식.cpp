#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;

size_t func(int st, int ed) {
	// 괄호가 닫힐 때, 비우고 나와야 하기 때문에 
	// 지역변수로 사용
	stack<char> s;

	int idx = ed;
	for (size_t i = st; i < ed; i++)
	{
		// 알파벳인 경우
		// 그냥 출력
		if ('A' <= str[i] && str[i] <= 'Z') {
			cout << str[i];
		}
		// '(' 일 경우 재귀
		// 반환 값으로 )의 위치 반환하여 인덱스 값 변환
		else if (str[i] == '(') {
			i = func(i + 1, ed);
		}
		// ')' 일 경우 내부의 연산자 전부 출력하고
		// 현재 인덱스 값 반환
		else if (str[i] == ')') {
			idx = i;
			break;
		}
		// '*', '/'는 '+','-'보다 우선순위가 높기 때문에
		// 다음 문자가 괄호일 경우 괄호 재귀,
		// 알파벳인 경우 알파벳 출력 후
		// 즉시 출력
		else if (str[i] == '*' || str[i] == '/') {
			s.push(str[i++]);
			if (str[i] == '(')
				i = func(i + 1, ed);
			else
				cout << str[i];

			cout << s.top();
			s.pop();

		}
		// '+', '-'는 직전의 연산자가 '+','-' 일 경우
		// 직전 값을 출력 후 입력
		else if (str[i] == '+' || str[i] == '-') {
			if (!s.empty() && (s.top() == '+' || s.top() == '-')) {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}

	// 순회가 종료된 후 전체 출력
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return idx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;

	func(0, str.length());

	return 0;
}