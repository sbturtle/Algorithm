#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define x first
#define y second

// �ܼ��ϰ� �����ϸ�, ġŲ���� ��ǥ���� ��� ���� ����
// ������ ����� ���� m���� ����
// ���� ��ġ�� ��� �� �ּҰŸ��� ����.
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m;
int map[51][51];
vector<pair<int, int>> hMap;
vector<pair<int, int>> ckMap;
int result = 1000000;
bool isUsed[15];

void func(int start, int k) {
    if (ckMap.size() - k == m) {
        


    }

    for (int i = start; i < n; i++)
    {
        if (!isUsed)
        {
            isUsed[i] = true;
            map[ckMap[i].x][ckMap[i].y] = 0;
            func(i + 1, k + 1);
            map[ckMap[i].x][ckMap[i].y] = 2;
            isUsed[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)
                hMap.push_back({ i,j });
            if (map[i][j] == 2)
                ckMap.push_back({ i,j });
        }
    }

    func(0, 0);

    return 0;
}