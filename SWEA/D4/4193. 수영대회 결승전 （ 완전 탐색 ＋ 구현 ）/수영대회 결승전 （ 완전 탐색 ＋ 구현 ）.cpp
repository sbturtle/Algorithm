#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

#define X first
#define Y second

int board[16][16];
int isvis[16][16];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;	cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
        		cin >> board[i][j];

        for(int i = 0; i < n; i++)
            fill(isvis[i], isvis[i] + 16, -1);
        
        pair<int, int> st;	cin >> st.X >> st.Y;
        pair<int, int> ed;	cin >> ed.X >> ed.Y;
        
        queue<pair<int, int>> q;
        q.push(st);
        isvis[st.X][st.Y] = 0;
        
        while(!q.empty()) {
        	auto cur = q.front(); q.pop();
            
            if(board[cur.X][cur.Y] == 2 && isvis[cur.X][cur.Y] % 3 != 0) {
                isvis[cur.X][cur.Y]++;
                q.push(cur);
                continue;
            }
            
			for(int i = 0; i < 4; i++) {
             	int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;                
                if(isvis[nx][ny] != -1 || board[nx][ny] == 1)
                    continue;
                
                isvis[nx][ny] = isvis[cur.X][cur.Y] + 1;
                q.push({nx, ny});
            }
        }
        
        
        
		cout << '#' << test_case << ' ' << isvis[ed.X][ed.Y] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}