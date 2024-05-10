#include <iostream>
#include <queue>
using namespace std;


// �߿䵵 ���ڰ� ��ĥ �� �ֱ� ������ ī���ù迭�� ����
// ť�� �ε��� ��ȣ, �߿䵵�� ����
// ī���� �迭�� �ִ밪�� ���ϴ� �ε����϶����� ���� ����
// ���ϴ� �ε����� ��� ���Ҵ� Ƚ�� ��ȯ 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int ip[10] = { 0, };
		int n, qt;
		queue<pair<int, int>> q;
		cin >> n >> qt;

		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			ip[x]++;
			q.push({ i,x });
		}

		int c = 1;
		while (true) {
			// �ְ��� �߿䵵 ã��
			int max = 0;
			for (int i = 9; i > 0; i--)
			{
				if (ip[i] != 0)
				{
					max = i;
					break;
				}
			}

			pair<int, int> temp = q.front(); q.pop();

			// �ְ��� �߿䵵���
			if (temp.second == max) {
				// �ְ� �߿䵵 �μ�
				ip[max]--;

				// �ε��� ã��.
				if (qt == temp.first)
					break;
				c++;
			}
			else {	// �ƴ϶�� �ڷ� �ѱ�
				q.push(temp);
			}
		}
		cout << c << '\n';
	}

	return 0;
}