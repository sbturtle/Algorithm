#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define X first
#define Y second

int n;
string board[301];
bool isvis[301][301];

int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};

bool FindMine(int x, int y) {
    int cnt = 0;
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;
        if(board[nx][ny] == '*')
            return true;
    }
    return false;
}

void Func(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x,y});
    isvis[x][y] = true;

    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        if(FindMine(cur.X, cur.Y))
            continue;

        for(int i = 0; i < 8; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if(isvis[nx][ny])
                continue;

            isvis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_case;
    int T;

    cin >> T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;
        int result = 0;

        for(int i = 0; i < n; i++)
            fill(isvis[i], isvis[i] + n, false);

        for(int i = 0; i < n; i++)
            cin >> board[i];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '*' || isvis[i][j])
                    continue;

                if(!FindMine(i,j)) {
                    Func(i,j);
                    result++;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '*' || isvis[i][j])
                    continue;
                
                result++;
            }
        }

        cout << '#' << test_case << ' ' << result << '\n';
    }
    return 0;
}
