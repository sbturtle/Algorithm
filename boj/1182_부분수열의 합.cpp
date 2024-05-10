#include <bits/stdc++.h>
using namespace std;

int N, s;
int arr[30];
int cnt = 0;

void func(int cur, int tot) {
    if (cur == N) {
        if (tot == s) cnt++;
        return;
    }
    func(cur + 1, tot);
    func(cur + 1, tot + arr[cur]);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> s;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    func(0, 0);
    if (s == 0) cnt--;
    cout << cnt;
}
