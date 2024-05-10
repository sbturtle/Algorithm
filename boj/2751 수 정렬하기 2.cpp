#include <bits/stdc++.h>
using namespace std;

int n;
int freq[1000001];
int tmp[1000001]; // merge �Լ����� ����Ʈ 2���� ��ģ ����� �ӽ÷� �����ϰ� ���� ����

// mid = (st+en)/2��� �� �� arr[st:mid], arr[mid:en]�� �̹� ������ �Ǿ��ִ� ������ �� arr[st:mid]�� arr[mid:en]�� ��ģ��.
void merge(int st, int en) {
	int mid = (st + en) / 2;

	int lidx = st;
	int ridx = mid;

	for (int i = st; i < en; i++)
	{
		if (ridx == en) tmp[i] = freq[lidx++];
		else if (lidx == mid) tmp[i] = freq[ridx++];
		else if (freq[lidx] <= freq[ridx]) tmp[i] = freq[lidx++];
		else tmp[i] = freq[ridx++];
	}

	for (int i = st; i < en; i++)
		freq[i] = tmp[i];
}

// arr[st:en]�� �����ϰ� �ʹ�.
void merge_sort(int st, int en) {
	if (st + 1 == en) return; // ���� 1�� ���
	int mid = (st + en) / 2;
	merge_sort(st, mid); // arr[st:mid]�� �����Ѵ�.
	merge_sort(mid, en); // arr[mid:en]�� �����Ѵ�.
	merge(st, en); // arr[st:mid]�� arr[mid:en]�� ��ģ��.
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)		cin >> freq[i];

	merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << freq[i] << '\n';  // -53 3 12 15 16 22 23 25 46 357
}