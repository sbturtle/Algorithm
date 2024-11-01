#include <iostream>
#include <set>
using namespace std;

// ���� ��ȣ �ε����� ���� ���̵� ���� �����ϴ� �迭
int ct[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// ���̵��� �������� ����
	set<pair<int, int>> ms;
	int N, M;

	cin >> N;
	while (N--) {
		int p, l;
		cin >> p >> l;
		ms.insert({ l,p });
		ct[p] = l;
	}

	cin >> M;
	while (M--) {
		string str;
		cin >> str;
		if (str == "add") {
			int p, l;
			cin >> p >> l;
			ms.insert({ l,p });
			ct[p] = l;

		}
		else if (str == "recommend") {
			int x; cin >> x;
			if (x == 1) {
				// �ִ� ���
				pair<int, int> iter = *ms.rbegin();
				cout << iter.second << '\n';
			}
			else {
				// �ּڰ� ���
				pair<int, int> iter = *ms.begin();
				cout << iter.second << '\n';
			}
		}
		else if (str == "solved") {
			// Ư�� �� ����
			int p; cin >> p;

			// pair�� �����ϰ� �ֱ� ������ find ���� pair�� ã�ƾ� ��..
			// ���� ct �迭�� ���� pair�� ����
			ms.erase({ ct[p],p });
		}
	}

	return 0;
}