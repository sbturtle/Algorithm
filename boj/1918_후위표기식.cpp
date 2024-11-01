#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;

size_t func(int st, int ed) {
	// ��ȣ�� ���� ��, ���� ���;� �ϱ� ������ 
	// ���������� ���
	stack<char> s;

	int idx = ed;
	for (size_t i = st; i < ed; i++)
	{
		// ���ĺ��� ���
		// �׳� ���
		if ('A' <= str[i] && str[i] <= 'Z') {
			cout << str[i];
		}
		// '(' �� ��� ���
		// ��ȯ ������ )�� ��ġ ��ȯ�Ͽ� �ε��� �� ��ȯ
		else if (str[i] == '(') {
			i = func(i + 1, ed);
		}
		// ')' �� ��� ������ ������ ���� ����ϰ�
		// ���� �ε��� �� ��ȯ
		else if (str[i] == ')') {
			idx = i;
			break;
		}
		// '*', '/'�� '+','-'���� �켱������ ���� ������
		// ���� ���ڰ� ��ȣ�� ��� ��ȣ ���,
		// ���ĺ��� ��� ���ĺ� ��� ��
		// ��� ���
		else if (str[i] == '*' || str[i] == '/') {
			s.push(str[i++]);
			if (str[i] == '(')
				i = func(i + 1, ed);
			else
				cout << str[i];

			cout << s.top();
			s.pop();

		}
		// '+', '-'�� ������ �����ڰ� '+','-' �� ���
		// ���� ���� ��� �� �Է�
		else if (str[i] == '+' || str[i] == '-') {
			if (!s.empty() && (s.top() == '+' || s.top() == '-')) {
				cout << s.top();
				s.pop();
			}
			s.push(str[i]);
		}
	}

	// ��ȸ�� ����� �� ��ü ���
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