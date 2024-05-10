#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define x first
#define y second

// 단순하게 생각하면, 치킨집의 좌표들을 모두 따로 저장
// 임의의 경우의 수로 m개씩 구성
// 집의 위치와 모두 각 최소거리를 구함.
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